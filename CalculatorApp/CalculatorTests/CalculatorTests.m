//
//  CalculatorTests.m
//  CalculatorTests
//
//  Created by Alex on 2/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#import <XCTest/XCTest.h>

#include "AppDelegate.h"
#include "ViewController.h"

@interface CalculatorTests : XCTestCase{
    @private
        ViewController *calcViewController;
        CalculatorBrain *brain;
        UIView *view;
}

@end

@implementation CalculatorTests

- (void)setUp
{
    [super setUp];
    
    calcViewController = [[ViewController alloc] init];
    brain = [[CalculatorBrain alloc] init];
    view = calcViewController.view;
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

-(NSString *)formatInputString:(NSArray *)inputString
{
    NSString *formatString = [[NSString alloc] init];
    NSNumberFormatter* nf = [[NSNumberFormatter alloc] init];
    
    for (NSString *str in inputString)
    {
        if ([nf numberFromString: str] != nil)
        {
            [brain setOperand: [str doubleValue]];
        }
        
        if ([[brain singleOperationList] containsObject: str])
        {
            [brain performSingleOperation:str];
        }
        
        formatString = [brain formatInputString:str];
    }
    
    return formatString;
}

-(double)calculateFromString
{
    return [brain calculateFromEquationString];
}

-(void)testValidInputString
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"3", @"x", @"4", @"-", @"5", nil];
 
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3x4-5");
}

-(void)testAnOperatorFollowBySingleOperator
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"±", @"3", @"x", @"4", nil];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3x4");
}

-(void)testACButtonPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"3", @"AC", @"4", @"+", @"5", nil];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"4+5");
}

-(void)testDelButtonPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"3", @"x", @"4", @"←", @"←", nil];
  
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3");
}

-(void)testContinuousOperatorPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"x", @"/", @"3", @"x", @"4", nil];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2/3x4");
}

-(void)testContinuousDigitPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"23", @"234", @"x", @"5", @"56", @"567", nil];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"234x567");
}

-(void)testSingleOperationPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"%", @"+", @"3", @"x", @"4", @"±", @"%", nil];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"0.02+3x-0.04");
}

-(void)testAnOperatorFirstPressed
{
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"+", @"2", nil];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"0+2");
}

-(void)testAddition
{
    double result;
    NSArray *inputString = [[NSArray alloc] initWithObjects:@"2", @"+", @"3", @"+", @"34", nil];
    
    NSString *formatString = [self formatInputString:inputString];
    result = [self calculateFromString];
    
    XCTAssertEqualObjects(formatString, @"2+3+34");
    XCTAssertEqual(result, 39);

}
@end
