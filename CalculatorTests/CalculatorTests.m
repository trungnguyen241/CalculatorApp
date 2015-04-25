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
        double result;
}

@end

@implementation CalculatorTests

- (void)setUp
{
    [super setUp];
    
    calcViewController = [[ViewController alloc] init];
    brain = [[CalculatorBrain alloc] init];
    view = calcViewController.view;
    result = 0.0;
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

-(double)calculateFromString: (NSArray *)inputString
{
    [self formatInputString:inputString];
    return [brain calculateFromEquationString];
}

-(void)testValidInputString
{
    NSArray *inputString = [@"2 + 3 x 4 - 5" componentsSeparatedByString: @" "];
 
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3x4-5");
}

-(void)testAnOperatorFollowBySingleOperator
{
    NSArray *inputString = [@"2 + ± 3 x 4" componentsSeparatedByString: @" "];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3x4");
}

-(void)testACButtonPressed
{
    NSArray *inputString = [@"2 + 3 AC 4 + 5" componentsSeparatedByString: @" "];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"4+5");
}

-(void)testDelButtonPressed
{
    NSArray *inputString = [@"2 + 3 x 4 ← ←" componentsSeparatedByString: @" "];
  
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2+3");
}

-(void)testContinuousOperatorPressed
{
    NSArray *inputString = [@"2 + x / 3 x 4" componentsSeparatedByString: @" "];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"2/3x4");
}

-(void)testContinuousDigitPressed
{
    NSArray *inputString = [@"2 23 234 x 5 56 567"componentsSeparatedByString: @" "];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"234x567");
}

-(void)testSingleOperationPressed
{
    NSArray *inputString = [@"2 % + 3 x 4 ± %" componentsSeparatedByString: @" "];
   
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"0.02+3x-0.04");
}

-(void)testAnOperatorFirstPressed
{
    NSArray *inputString = [@"+ 2" componentsSeparatedByString: @" "];
    
    NSString *formatString = [self formatInputString:inputString];
    
    XCTAssertEqualObjects(formatString, @"0+2");
}

-(void)testSimpleAddition
{
    NSArray *inputString = [@"2 + 3 + 34" componentsSeparatedByString: @" "];

    result = [self calculateFromString:inputString];
    
    XCTAssertEqual(result, 39);

}

-(void)testSimpleSubtraction
{
    NSArray *inputString = [@"2 - 3 - 34" componentsSeparatedByString: @" "];
    
    result = [self calculateFromString:inputString];
    
    XCTAssertEqual(result, -35);
    
}

-(void)testSimpleMultiplication
{
    NSArray *inputString = [@"2 x 3 x 34" componentsSeparatedByString: @" "];
    
    result = [self calculateFromString:inputString];
    
    XCTAssertEqual(result, 204);
    
}

-(void)testSimpleDivision
{
    NSArray *inputString = [@"2 / 3 / 34" componentsSeparatedByString: @" "];
    
    result = [self calculateFromString:inputString];
    
    XCTAssertEqual(result, 0.02);
    
}

-(void)testOperatorPrecedence
{
    NSArray *inputString = [@"1 + 2 x 3 + 4 - 6 / 3 + 2 x 3 x 4" componentsSeparatedByString: @" "];
    
    result = [self calculateFromString:inputString];
    
    XCTAssertEqual(result, 33);
}

-(void)testSingleOperator
{
    NSArray *inputString = [@"5 %" componentsSeparatedByString: @" "];
    result = [self calculateFromString:inputString];
    XCTAssertEqual(result, 0.05);
    
    inputString = [@"5 ±" componentsSeparatedByString: @" "];
    result = [self calculateFromString:inputString];
    XCTAssertEqual(result, -5);
}
@end
