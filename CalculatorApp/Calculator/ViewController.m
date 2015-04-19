//
//  ViewController.m
//  Calculator
//
//  Created by Alex on 2/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#import "ViewController.h"
#import "CalculatorBrain.h"

@interface ViewController ()


@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    for (UIButton *button in collectionButtons)
    {
            //NSLog(@"button: %@ tag: %ld", [[button titleLabel] text], (long)[button tag]);
        button.layer.borderWidth = .5f;
        button.layer.borderColor = [UIColor blackColor].CGColor;
    }
  
    [self willAnimateRotationToInterfaceOrientation: [[UIApplication sharedApplication] statusBarOrientation] duration:0.0];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

-(void) willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
    double screenWidth = [UIScreen mainScreen].bounds.size.width;
    double screenHeight = [UIScreen mainScreen].bounds.size.height;
    double buttonWidth = screenWidth / 4;
    double buttonHeight = 40;
    double currentCordinateX = screenWidth ;
    double currentCordinateY = screenHeight ;
    
        //NSLog(@"%f  %f", screenWidth, screenHeight);
    
    for (UIButton *button in collectionButtonsLandscape)
    {
        button.hidden = TRUE;
    }
    
    if (toInterfaceOrientation == UIInterfaceOrientationPortrait ||
        toInterfaceOrientation == UIInterfaceOrientationPortraitUpsideDown)
    {
        for (UIButton *button in collectionButtons)
        {
            button.hidden = FALSE;
            buttonWidth = screenWidth / 4;
            
            if (currentCordinateX == 0 || currentCordinateX == screenWidth)
            {
                currentCordinateX = screenWidth - buttonWidth;
                currentCordinateY -= buttonHeight;
            }
            else
            {
                currentCordinateX -= buttonWidth;
            }
            
                //NSLog(@"Button %@, x = %.0f,  y = %.0f", [[button titleLabel] text], currentCordinateX, currentCordinateY);
            
            button.frame = CGRectMake(currentCordinateX, currentCordinateY, buttonWidth, buttonHeight);
        }
    }
    else if (toInterfaceOrientation == UIInterfaceOrientationLandscapeLeft ||
        toInterfaceOrientation == UIInterfaceOrientationLandscapeRight)
    {
        screenWidth = [UIScreen mainScreen].bounds.size.height;
        screenHeight = [UIScreen mainScreen].bounds.size.width;
    }
    
    displayNumber.frame = CGRectMake(screenWidth - 10, 50, -screenWidth, 30);
    displayEquation.frame = CGRectMake(screenWidth - 10, 100, -screenWidth, 20);

  }

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
        // Dispose of any resources that can be recreated.
}

-(CalculatorBrain *) brain
{
    if(!brain)
    {
        brain = [[CalculatorBrain alloc] init];
    }
    return brain;
}

- (IBAction)digitPressed:(UIButton *)sender
{
    NSString* digit = [[sender titleLabel] text];
    
    if (isEqualButtonJustPressed)
    {
        [self resetDisplayNumber];
        isEqualButtonJustPressed = FALSE;
    }
    
    if (userIsInTheMiddleOfTypingANumber)
    {
        digit = [[displayNumber text] stringByAppendingString:digit];
    }
    else
    {
        userIsInTheMiddleOfTypingANumber = YES;
    }
    
    [displayNumber setText:digit];
    
    [self updateEquationString: digit];
}

- (IBAction)operationPressed:(UIButton *)sender
{
    userIsInTheMiddleOfTypingANumber = NO;
    
    NSString* operation = [[sender titleLabel] text];
    [self updateEquationString:operation];
        //[displayNumber setText:[NSString stringWithFormat:@"%g", result]];
}

- (IBAction)singleOperationPressed:(id)sender
{
    [self.brain setOperand: [[displayNumber text] doubleValue]];
    userIsInTheMiddleOfTypingANumber = NO;
    
    NSString* operation = [[sender titleLabel] text];
    double result = [self.brain performSingleOperation: operation];
    
    [self updateEquationString: operation];
    [displayNumber setText:[NSString stringWithFormat:@"%g", result]];
}

- (IBAction)equalButtonPressed:(id)sender
{
    double result = [self.brain performEqualOperation];
    [displayNumber setText:[NSString stringWithFormat:@"%g", result]];
    
    isEqualButtonJustPressed = TRUE;
}

- (void)updateEquationString:(NSString *)appendString
{
    [self.brain formatInputString: appendString];
    NSLog(@"input string = %@", [self.brain inputString]);
    
    NSString *equationString = [[self.brain inputString] componentsJoinedByString:@""];
    NSLog(@"string = %@", equationString);
    
    [displayEquation setText: equationString];
}

-(void) resetDisplayNumber{
    [displayNumber setText:@""];
}

@end
