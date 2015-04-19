//
//  CalculatorBrain.h
//  Calculator
//
//  Created by Alex on 2/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CalculatorBrain : NSObject

@property double operand;
@property (strong,atomic) NSMutableArray *inputString;

@property NSArray *operationList;
@property NSArray *singleOperationList;

- (double) performSingleOperation: (NSString *) operation;

- (double) performEqualOperation;

- (NSString *) formatInputString: (NSString *) appendString;
- (BOOL) isContinuousDigitPressed:(NSString *)appendString;
- (BOOL)isContinuousOperatorPressed:(NSString *) appendString;
- (BOOL)isAnOperatorFollowBySingleOperator:(NSString *) appendString;
- (BOOL)isACButtonPressed:(NSString *) appendString;
- (BOOL)isDelButtonPressed:(NSString *) appendString;
- (BOOL)isSingleOperationPressed:(NSString *) appendString;

- (double) calculateFromEquationString;
- (BOOL) inputStringContain: (NSString *) anOperator;
- (BOOL) objectAtIndex: (int) anIndex equalOperator: (NSString*) anOperator;
- (NSIndexSet *)createIndexSetFrom:(int)firstIndex to:(int)lastIndex;
- (NSMutableArray *) createSubEquationInRange: (NSIndexSet *) indexSet;

- (double) calculateFromSubEquationString: (NSMutableArray *) subEquationString;
@end
