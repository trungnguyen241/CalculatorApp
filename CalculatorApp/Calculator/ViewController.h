//
//  ViewController.h
//  Calculator
//
//  Created by Alex on 2/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CalculatorBrain.h"

@interface ViewController : UIViewController{
    
    IBOutletCollection(UIButton) NSArray *collectionButtons;
    IBOutletCollection(UIButton) NSArray *collectionButtonsLandscape;
    
    CalculatorBrain* brain;
    IBOutlet UILabel *displayNumber;
    BOOL userIsInTheMiddleOfTypingANumber;
    BOOL isEqualButtonJustPressed;
    IBOutlet UILabel *displayEquation;
  
}

- (void)setButtonBorder: (NSArray *)button;
- (void) hideButton: (NSArray *)buttonsCollection;
- (void) setButtonLocationIn: (NSArray *)buttonsCollection atCordX :(double)cordX andCordY: (double) cordY withButtonWidth: (double)buttonWidth andButtonHeight:(double)buttonHeight screenWidth: (double)screenWidth andScreenHeight: (double)screenHeight;

- (IBAction) digitPressed:(UIButton *)sender;
- (IBAction) operationPressed:(UIButton *)sender;
- (IBAction) singleOperationPressed:(id)sender;
- (IBAction) equalButtonPressed:(id)sender;
- (void) updateEquationString:(NSString *)appendString;
- (void) resetDisplayNumber;

@end
