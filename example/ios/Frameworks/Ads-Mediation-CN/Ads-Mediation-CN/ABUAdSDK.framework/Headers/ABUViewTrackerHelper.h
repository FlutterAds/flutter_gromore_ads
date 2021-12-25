//
//  ABUViewTrackerHelper.h
//  ABUAdSDK
//
//  Created by wangchaop on 22/06/2020.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ABUViewTrackerHelper : NSObject

+ (BOOL)checkIfViewInScreen:(UIView *)view;

/// 当前屏幕内展示的面积
+ (CGFloat)visibleAreaWithView:(UIView *)view;

@end
