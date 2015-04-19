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
        CalculatorBrain *calcBrain;
        UIView *view;
}

//@property ViewController *calcViewController;
//@property CalculatorBrain *calcBrain;
@end

@implementation CalculatorTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    calcViewController = [[ViewController alloc] init];
    calcBrain = [[CalculatorBrain alloc] init];
    view = calcViewController.view;
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

@end
