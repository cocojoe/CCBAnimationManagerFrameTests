/*
 * SpriteBuilder: http://www.spritebuilder.org
 *
 * Copyright (c) 2012 Zynga Inc.
 * Copyright (c) 2013 Apportable Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "cocos2d.h"

#define CCBAnimationManager             CCAnimationManager
#define CCBAnimationManagerDelegate     CCAnimationManagerDelegate

@class CCAnimationSequence;

#pragma mark Animation Manager Delegate

@protocol CCAnimationManagerDelegate <NSObject>

- (void)completedAnimationSequenceNamed:(NSString*)name;

@end

#pragma mark Animation Manager

@interface CCAnimationManager : NSObject <CCSchedulerTarget>
{
    NSMutableArray* sequences;
    NSMutableDictionary* nodeSequences;
    NSMutableDictionary* baseValues;
    int autoPlaySequenceId;
    
    NSInteger animationManagerId;
    
    CCNode* __unsafe_unretained rootNode;
    id __unsafe_unretained owner;
    CGSize rootContainerSize;
    
    NSObject<CCAnimationManagerDelegate>* delegate;
    CCAnimationSequence* runningSequence;
    
    void (^block)(id sender);
    
    CCScheduler* _scheduler;
    NSMutableArray* _currentActions;
    
}

@property (nonatomic,readonly) NSMutableArray* sequences;
@property (nonatomic,assign) int autoPlaySequenceId;
@property (nonatomic,unsafe_unretained) CCNode* rootNode;
@property (nonatomic,unsafe_unretained) id owner;
@property (nonatomic,assign) CGSize rootContainerSize;
@property (nonatomic,strong) NSObject<CCAnimationManagerDelegate>* delegate;
@property (unsafe_unretained, nonatomic,readonly) NSString* runningSequenceName;
@property (nonatomic,readonly) NSString* lastCompletedSequenceName;

@property (nonatomic,assign) float playbackSpeed;
@property (nonatomic,assign) bool paused;

- (CGSize) containerSize:(CCNode*)node;

- (void) addNode:(CCNode*)node andSequences:(NSDictionary*)seq;
- (void) moveAnimationsFromNode:(CCNode*)fromNode toNode:(CCNode*)toNode;

- (void) setBaseValue:(id)value forNode:(CCNode*)node propertyName:(NSString*)propName;

- (void) runAnimationsForSequenceNamed:(NSString*)name;
- (void) runAnimationsForSequenceNamed:(NSString*)name tweenDuration:(float)tweenDuration;
- (void) runAnimationsForSequenceId:(int)seqId tweenDuration:(float) tweenDuration;

- (void) setCompletedAnimationCallbackBlock:(void(^)(id sender))b;

- (void) timeSeekForSequenceNamed:(NSString*)name time:(float)time;
- (void) timeSeekForSequenceId:(int)seqId time:(float)time;

@end
