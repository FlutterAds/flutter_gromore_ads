//
//  ABUNewSplashZoomOutView.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/8/13.
//

#import <UIKit/UIKit.h>
#import "ABUZoomOutViewProperty.h"
#import "ABUAdSDKConst.h"

NS_ASSUME_NONNULL_BEGIN


@class ABUSplashZoomOutView;

/// zoom out view代理协议
@protocol ABUZoomOutSplashAdDelegate <NSObject>
@optional
/// This method is called when splash ad is clicked.
/// @param splashZoomOutView zoom out view


/// 开屏广告zoomoutview点击事件回调
/// @param splashZoomOutView zoom out view
- (void)splashZoomOutViewAdDidClick:(UIView *_Nonnull)splashZoomOutView;

/// 开屏广告zoomoutview关闭事件回调
/// @param splashZoomOutView zoom out view
- (void)splashZoomOutViewAdDidClose:(UIView *_Nonnull)splashZoomOutView;

/// 开屏广告zoomoutview已经打开全屏页面事件回调
/// @param splashZoomOutView zoom out view
- (void)splashZoomOutViewAdDidPresentFullScreenModal:(UIView *_Nonnull)splashZoomOutView;

/// 开屏广告zoomoutview已经关闭全屏页面事件回调
/// @param splashZoomOutView zoom out view
- (void)splashZoomOutViewAdDidDismissFullScreenModal:(UIView *_Nonnull)splashZoomOutView;

@end

/// 开屏 zoom out view
@interface ABUSplashZoomOutView : UIView

/// 跳转控制器
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

/// 代理对象
@property (nonatomic, weak, nullable) id<ABUZoomOutSplashAdDelegate> delegate;

/// 建议展示尺寸
@property (nonatomic, assign, readonly) CGSize suggestedSize;

/// zoom out view 是否有自己的动画实现
@property (nonatomic, assign, readonly) BOOL hasAnimation;

/// 开屏点睛处理时机
@property (nonatomic, assign) ABUAddOccasionType addOccasionType;
@end

NS_ASSUME_NONNULL_END
