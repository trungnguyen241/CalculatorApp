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

    [self setButtonBorder:collectionButtons];
    [self setButtonBorder:collectionButtonsLandscape];
    
    [self willAnimateRotationToInterfaceOrientation: [[UIApplication sharedApplication] statusBarOrientation] duration:0.0];
}

-(void)setButtonBorder: (NSArray *) buttonsCollection
{
    for (UIButton *button in buttonsCollection)
    {
        button.layer.borderWidth = .5f;
        button.layer.borderColor = [UIColor blackColor].CGColor;
    }
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

-(void) willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
    double screenWidth;
    double screenHeight;
    double buttonWidth;
    double buttonHeight;
    double currentCordinateX;
    double currentCordinateY;
    
    if (toInterfaceOrientation == UIInterfaceOrientationPortrait ||
        toInterfaceOrientation == UIInterfaceOrientationPortraitUpsideDown)
    {
        screenWidth = [UIScreen mainScreen].bounds.size.width;
        screenHeight = [UIScreen mainScreen].bounds.size.height;
        buttonWidth = screenWidth / 4;
        buttonHeight = 40;
        currentCordinateX = screenWidth;
        currentCordinateY = screenHeight;
        
        [self hideButton:collectionButtonsLandscape];
        
        [self setButtonLocationIn:collectionButtons atCordX:currentCordinateX andCordY:currentCordinateY withButtonWidth:buttonWidth andButtonHeight:buttonHeight screenWidth:screenWidth andScreenHeight:screenHeight];
    }
    else
    {
        screenWidth = [UIScreen mainScreen].bounds.size.height;
        screenHeight = [UIScreen mainScreen].bounds.size.width;
        buttonWidth = screenWidth / 10;
        buttonHeight = 30;
        currentCordinateX = screenWidth ;
        currentCordinateY = screenHeight ;
    
        [self hideButton:collectionButtons];
        
        [self setButtonLocationIn:collectionButtonsLandscape atCordX:currentCordinateX andCordY:currentCordinateY withButtonWidth:buttonWidth andButtonHeight:buttonHeight screenWidth:screenWidth andScreenHeight:screenHeight];
    }

    displayNumber.frame = CGRectMake(screenWidth - 10, 50, -screenWidth, 30);
    displayEquation.frame = CGRectMake(screenWidth - 10, 100, -screenWidth, 20);

  }

- (void) hideButton: (NSArray *)buttonsCollection
{
    for (UIButton *button in buttonsCollection)
    {
        button.hidden = TRUE;
    }
}

- (void) setButtonLocationIn: (NSArray *)buttonsCollection atCordX :(double)cordX andCordY: (double) cordY withButtonWidth: (double)buttonWidth andButtonHeight:(double)buttonHeight screenWidth: (double)screenWidth andScreenHeight: (double)screenHeight
{
    for (UIButton *button in buttonsCollection)
    {
        button.hidden = FALSE;
        
        if ((int)cordX == 0 || (int)cordX == screenWidth)
        {
            cordX = screenWidth - buttonWidth;
            cordY -= buttonHeight;
        }
        else
        {
            cordX -= buttonWidth;
        }
        
        button.frame = CGRectMake(cordX, cordY, buttonWidth, buttonHeight);
    }
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
    NSString *equationString = [self.brain formatInputString: appendString];
    
    [displayEquation setText: equationString];
}

-(void) resetDisplayNumber{
    [displayNumber setText:@""];
}

@end
