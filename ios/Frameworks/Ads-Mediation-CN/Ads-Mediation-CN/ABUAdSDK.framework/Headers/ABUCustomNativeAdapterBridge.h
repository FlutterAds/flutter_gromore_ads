//
//  ABUCustomNativeAdapterBridge.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import <Foundation/Foundation.h>
#import "ABUMediatedNativeAd.h"
#import "ABUPlayerPlayState.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ABUCustomNativeAdapter,ABUDislikeWords;

/// 自定义Native广告的adapter的回调协议
@protocol ABUCustomNativeAdapterBridge <NSObject>
@optional

#pragma mark - Load
/// 在非模板广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ads 广告数据组
/// @param exts 扩展数据组
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didLoadWithNativeAds:(NSArray<ABUMediatedNativeAd *> * _Nullable)ads exts:(NSArray<NSDictionary *> * _Nullable)exts;

/// 在模板广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param views 广告视图数据组
/// @param exts 扩展数据组
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didLoadWithExpressViews:(NSArray<UIView *> * _Nullable)views exts:(NSArray<NSDictionary *> * _Nullable)exts;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;

#pragma mark - View

/// 广告展示时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didVisibleWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 广告点击事件时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didClickWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter willPresentFullScreenModalWithMediatedNativeAd:(id _Nonnull)nativeAd;

/// 在广告落地页关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didDismissFullScreenModalWithMediatedNativeAd:(id _Nonnull)nativeAd;

#pragma mark - Express ad
/// 仅限模板广告，在渲染成功或者模板广告的尺寸更新时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter renderSuccessWithExpressView:(UIView *_Nonnull)expressView;

/// 仅限模板广告，在渲染失败调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter renderFailWithExpressView:(UIView *_Nonnull)expressView andError:(NSError *_Nonnull)error;

/// 仅限模板广告，在模板广告关闭的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告
/// @param filterWords 用户手动关闭时的关闭原因描述
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter didCloseWithExpressView:(UIView *_Nonnull)expressView closeReasons:(NSArray<ABUDislikeWords *> *_Nullable)filterWords;

#pragma mark - video

/// 视频广告中视频播放状态变更的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param state 播放状态
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter videoStateDidChangedWithState:(ABUPlayerPlayState)state andNativeAd:(id _Nonnull)nativeAd;

/// 视频广告中视频视图被点击时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter videoDidClick:(id _Nonnull)nativeAd;

/// 视频广告中视频播放完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param nativeAd 广告数据，native广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），express广告请传递上报GroMore的UIView
- (void)nativeAd:(id<ABUCustomNativeAdapter>_Nonnull)adapter videoDidPlayFinish:(id _Nonnull)nativeAd;

@end

NS_ASSUME_NONNULL_END
