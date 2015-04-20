//
//  CalculatorBrain.m
//  Calculator
//
//  Created by Alex on 2/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#import "CalculatorBrain.h"

@implementation CalculatorBrain

- (id) init{
    self = [super init];
    
    if(self){
        self.operand = 0;
        self.inputString = [[NSMutableArray alloc] init];
        
        self.operationList = [[NSArray alloc] initWithObjects:@"+", @"-", @"x", @"/", nil];
        self.singleOperationList = [[NSArray alloc] initWithObjects:@"←", @"%", @"±", @"AC", @"Rand", nil];
    }
    return self;
}

- (double) performSingleOperation:(NSString *)operation
{
    if ([operation isEqual:@"AC"])
    {
        self.operand = 0;
        [self.inputString removeAllObjects];
    }
    else if ([operation isEqual:@"←"])
    {
        [self.inputString removeLastObject];
    }
    else if ([operation isEqual:@"±"])
    {
        self.operand = (-1) * self.operand;
    }
    else if([operation isEqual:@"%"])
    {
        self.operand = self.operand / 100;
    }
    else if ([operation isEqual:@"Rand"])
    {
        self.operand = arc4random() / pow(2, 32);
    }

    return self.operand;
}

- (double) performEqualOperation
{
    self.operand = [self calculateFromEquationString];
    
    self.inputString = [[NSMutableArray alloc] init];
    
    return self.operand;
}

- (NSString *) formatInputString:(NSString *)appendString
{
    if ([self isAnOperatorFollowBySingleOperator:appendString] ||
        [self isACButtonPressed:appendString] ||
        [self isDelButtonPressed:appendString])
    {
            //do nothing
    }
    else if ([self isContinuousOperatorPressed:appendString] ||
        [self isContinuousDigitPressed:appendString])
    {
        [self.inputString removeLastObject];
        [self.inputString addObject: appendString];
    }
    else if ([self isSingleOperationPressed:appendString])
    {
        [self.inputString removeLastObject];
        [self.inputString addObject: [NSString stringWithFormat:@"%g", self.operand]];
    }
    else if ([self isAnOperatorFirstPressed:appendString])
    {
        [self.inputString insertObject:[NSNumber numberWithDouble: self.operand] atIndex:0];
        [self.inputString addObject: appendString];
    }
    else
    {
        [self.inputString addObject: appendString];
    }
    
    NSLog(@"input string = %@", self.inputString);
    NSString *equationString = [self.inputString componentsJoinedByString:@""];
    NSLog(@"string = %@", equationString);
    
    return equationString;

}

- (BOOL)isAnOperatorFirstPressed:(NSString *) appendString
{
    BOOL isFirstObjectInInputStringAnOperator = [self.operationList containsObject: appendString];
    
    if (([self.inputString count] == 0) &&
        isFirstObjectInInputStringAnOperator)
    {
        NSLog(@"-->an operator is first pressed");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isContinuousDigitPressed:(NSString *)appendString
{
    NSNumberFormatter* nf = [[NSNumberFormatter alloc] init];
    BOOL isLastObjectInInputStringANumber = [nf numberFromString: [self.inputString lastObject]] != nil;
    BOOL isAppendStringANumber = [nf numberFromString: appendString] != nil;
    
    if ((isLastObjectInInputStringANumber || [[self.inputString lastObject] isEqual:@"."])
        && isAppendStringANumber)
    {
        NSLog(@"-->continuous operands");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isContinuousOperatorPressed:(NSString *) appendString
{
    BOOL isLastObjectInInputStringAnOperator = [self.operationList containsObject: [self.inputString lastObject]];
    BOOL isAppendStringAnOperator = [self.operationList containsObject: appendString];
    
    if (isLastObjectInInputStringAnOperator && isAppendStringAnOperator)
    {
        NSLog(@"-->continuous operators");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isAnOperatorFollowBySingleOperator:(NSString *) appendString
{
        //operator follows by singleOperator
    BOOL isLastObjectInInputStringAnOperator = [self.operationList containsObject: [self.inputString lastObject]];
    BOOL isAppendStringASingleOperation = [self.singleOperationList containsObject: appendString];
    
    if (isLastObjectInInputStringAnOperator && isAppendStringASingleOperation)
    {
        NSLog(@"-->operator follows by singleOperator");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isACButtonPressed:(NSString *) appendString
{
    if ([appendString isEqual:@"AC"])
    {
        NSLog(@"-->AC is pressed");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isDelButtonPressed:(NSString *) appendString
{
    if ([appendString isEqual:@"←"])
    {
        NSLog(@"-->Del is pressed");
        return TRUE;
    }
    
    return FALSE;
}

- (BOOL)isSingleOperationPressed:(NSString *) appendString
{
    if ([self.singleOperationList containsObject: appendString])
    {
        NSLog(@"-->single operator pressed");
        return TRUE;
    }
    
    return FALSE;
}

-(double) calculateFromEquationString {
    
    NSMutableArray *subEquationString = [[NSMutableArray alloc] init];
    NSIndexSet *indexSet;
    double result = 0;
    
    while ([self inputStringContain:@"x"] || [self inputStringContain:@"/"])
    {
        int lastIndex = 0;
        
        for (int operatorIndex = 1; operatorIndex < [self.inputString count]; operatorIndex +=2)
        {
            if ([self objectAtIndex: operatorIndex equalOperator:@"x"] ||
                [self objectAtIndex: operatorIndex equalOperator:@"/"])
            {
                for (lastIndex = operatorIndex; (lastIndex + 2 < [self.inputString count]) &&
                     ([self objectAtIndex: (lastIndex + 2) equalOperator:@"x"] ||
                      [self objectAtIndex: (lastIndex + 2) equalOperator:@"/"]);
                     lastIndex += 2);
                
                indexSet = [self createIndexSetFrom:operatorIndex to:lastIndex];
                
                subEquationString = [self createSubEquationInRange: indexSet];
                
                result = [self calculateFromSubEquationString: subEquationString];
                [subEquationString removeAllObjects];
                
                [self.inputString removeObjectsAtIndexes:indexSet];
                NSLog(@"inputString = %@", self.inputString);
                
                [self.inputString insertObject: [NSNumber numberWithDouble:result] atIndex: (operatorIndex - 1)];
                NSLog(@"inputString = %@", self.inputString);
                
                break;
            }
        }
    }
    
    if (!([self inputStringContain:@"x"] || [self inputStringContain:@"/"]))
    {
        subEquationString = self.inputString;
    }
    
    result = [self calculateFromSubEquationString: subEquationString];
    
    
    return result;
}


- (BOOL) inputStringContain: (NSString *) anOperator
{
    return [self.inputString containsObject:anOperator];
}

- (BOOL) objectAtIndex: (int) anIndex equalOperator: (NSString*) anOperator
{
    return [[self.inputString objectAtIndex: anIndex] isEqual: anOperator];
}

- (NSIndexSet *)createIndexSetFrom:(int)firstIndex to:(int)lastIndex {
        //NSMakeRange (index, lengthFromIndex)
    int length;
    NSIndexSet *indexSet;
    
    length = (lastIndex + 1) - (firstIndex - 1) + 1;
    indexSet = [NSIndexSet indexSetWithIndexesInRange: NSMakeRange(firstIndex - 1, length)];
    NSLog(@"indexSet = %@", indexSet);
    
    return indexSet;
}

- (NSMutableArray *) createSubEquationInRange: (NSIndexSet *) indexSet
{
    NSMutableArray *subEquationString = [[NSMutableArray alloc] init];
    
    [subEquationString addObjectsFromArray: [self.inputString objectsAtIndexes: indexSet]];
    NSLog(@"subEquationString = %@", subEquationString);
    
    return subEquationString;
}

-(double) calculateFromSubEquationString:(NSMutableArray *)subEquationString {
    
    if ([subEquationString count] == 0)
        return self.operand;
    
    double result = 0;
    NSString* operation;
    double operand = 0;
    
    result = [[subEquationString objectAtIndex: 0] doubleValue];
    for (int operatorIndex = 1; operatorIndex < [subEquationString count]; operatorIndex += 2)
    {
        operation = [subEquationString objectAtIndex: operatorIndex];
        operand = [[subEquationString objectAtIndex: operatorIndex + 1] doubleValue];
        
        NSLog(@"calculate: %f %@ %f", result, operation, operand);
        
        if ([operation isEqual:@"+"]) {
            result += operand;
        }
        else if ([operation isEqual:@"-"]) {
            result -= operand;
        }
        else if ([operation isEqual:@"x"]) {
            result *= operand;
        }
        else if ([operation isEqual:@"/"]) {
            result = round((result / operand) * 100.0) / 100.0;
        }
    }
    
    NSLog(@"result: %f", result);
    
    return result;
}
    

@end
