//
//  IntroScene.m
//  animationdevelop
//
//  Created by Martin Walsh on 10/03/2014.
//  Copyright Pedro 2014. All rights reserved.
//
// -----------------------------------------------------------------------

// Import the interfaces
#import "IntroScene.h"
#import "CCBAnimationManager+FrameAnimation.h"

// -----------------------------------------------------------------------
#pragma mark - IntroScene
// -----------------------------------------------------------------------

@implementation IntroScene

// -----------------------------------------------------------------------
#pragma mark - Create & Destroy
// -----------------------------------------------------------------------

+ (IntroScene *)scene
{
	return [[self alloc] init];
}

// -----------------------------------------------------------------------

- (id)init
{
    // Apple recommend assigning self with supers return value
    self = [super init];
    if (!self) return(nil);
    
    // Create a colored background (Dark Grey)
    CCNodeColor *background = [CCNodeColor nodeWithColor:[CCColor colorWithRed:0.2f green:0.2f blue:0.2f alpha:1.0f]];
    [self addChild:background];
    
    // Hello world
    CCLabelTTF *label = [CCLabelTTF labelWithString:@"Dance" fontName:@"Chalkduster" fontSize:36.0f];
    label.positionType = CCPositionTypeNormalized;
    label.color = [CCColor redColor];
    label.position = ccp(0.5f, 0.85f); // Middle of screen
    [self addChild:label];
    
    // Load Sprite Sheet
    [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:@"grossini_blue.plist" textureFilename:@"grossini_blue.png"];
    [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:@"grossini-aliases.plist" textureFilename:@"grossini-aliases.png"];
    [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:@"grossini_gray.plist" textureFilename:@"grossini_gray.png"];
    
    // Add Grossini Character
    CCSprite* grossini = [CCSprite spriteWithImageNamed:@"grossini_dance_05.png"];
    grossini.position  = ccp(240,160);
    [self addChild:grossini z:10];
    
    // Setup Animation Manager
    CCBAnimationManager* grossiniAnimation = [[CCBAnimationManager alloc] init];
    [grossiniAnimation setRootNode:grossini];
    
    [grossiniAnimation addAnimationsWithFile:@"animations-2.plist" node:grossini];
    
    //NSArray* animFrames = @[@"grossini_dance_03.png",@"grossini_blue_02.png",@"grossini_blue_03.png",@"grossini_blue_04.png"];
    //[grossiniAnimation animationWithSpriteFrames:animFrames delay:0.15f name:@"dance_4" node:grossini loop:YES];
    
    // Dance Grossini
    [grossiniAnimation runAnimationsForSequenceNamed:@"dance_1"];

	return self;
}

@end
