//
//  ABUViewTracker.h
//  ABUAdSDK
//
//  Created by wangchaop on 22/06/2020.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, ABUViewTrackerRepeatType) {
    ABUViewTrackerRepeatType_none   = 1,          //上报一次
    ABUViewTrackerRepeatType_repeat = 2,          //重复检测上报
};

typedef NS_ENUM (NSInteger, ABUViewTrackerLastPresentation) {
    ABUViewTrackerLastPresentation_outScreen = 0,        //上次检测的上报时在屏幕外
    ABUViewTrackerLastPresentation_inScreen  = 1,        //上次检测的上报时在屏幕上
};

@protocol ABUViewTracker <NSObject>
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) ABUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) ABUViewTrackerLastPresentation lastPresentation;
@property (nonatomic, assign) NSTimeInterval showTimestamp;
@property (nonatomic, copy) void (^ showEvent)(id<ABUViewTracker>);
@property (nonatomic, copy) void (^ hideEvent)(id<ABUViewTracker>);
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, strong) id admodel;

- (BOOL)invalid;
- (BOOL)checkIfViewInScreen;
- (void)snapShot;

@end

/*
 BUViewTracker用于单个view
 */
@interface ABUViewTracker : NSObject <ABUViewTracker>
@property (nonatomic, weak) UIView *view;
@property (nonatomic, strong) id admodel;
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) ABUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) ABUViewTrackerLastPresentation lastPresentation;
@property (nonatomic, copy) void (^ showEvent)(id<ABUViewTracker> tracker);
@property (nonatomic, copy) void (^ hideEvent)(id<ABUViewTracker> tracker);
@property (nonatomic, assign) NSTimeInterval showTimestamp;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, copy) NSString *tag;

- (BOOL)checkIfViewInScreen;
- (BOOL)invalid;

@end

/*
 ABUNativeViewTracker用于多个view
 */
@interface ABUNativeViewTracker : NSObject  <ABUViewTracker>
@property (nonatomic, strong) NSPointerArray *views;
@property (nonatomic, strong) id admodel;
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) ABUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) ABUViewTrackerLastPresentation lastPresentation;
@property (nonatomic, copy) void (^ showEvent)(id<ABUViewTracker>);
@property (nonatomic, copy) void (^ hideEvent)(id<ABUViewTracker>);
@property (nonatomic, assign) NSTimeInterval showTimestamp;
@property (nonatomic, copy) NSString *tag;

- (BOOL)checkIfViewInScreen;
- (BOOL)invalid;

@end
