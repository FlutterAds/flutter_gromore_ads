//
//  ABUCustomSplashAdapterBridge.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import <Foundation/Foundation.h>
#import "ABUZoomOutViewProperty.h"
#import "ABUCardViewProperty.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ABUCustomSplashAdapter;

/// 自定义开屏广告的adapter的回调协议
@protocol ABUCustomSplashAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)splashAd:(id<ABUCustomSplashAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)splashAd:(id<ABUCustomSplashAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在广告加载完成后如果存在zoomview时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param view zoom out view
/// @param property zoom out view属性
- (void)splashAd:(id<ABUCustomSplashAdapter>)adapter hasZoomOutView:(UIView *)view withProperty:(void(^)(ABUZoomOutViewProperty *prop))property;

/// 在广告加载完成后如果存在cardView时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param view cardView
- (void)splashAd:(id<ABUCustomSplashAdapter>)adapter hasCardView:(UIView *)view withProperty:(void(^)(ABUCardViewProperty *prop))property;

/// 在广告即将展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillVisible:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAdDidShowFailed:(id<ABUCustomSplashAdapter>)adapter error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClick:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClickSkip:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClose:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillPresentFullScreenModal:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillDismissFullScreenModal:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在模板广告渲染成功时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidRenderSuccess:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAd:(id<ABUCustomSplashAdapter>_Nonnull)adapter didRenderFailedWithError:(NSError *)error;

/// 在广告倒计时结束时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidCountDownToZero:(id<ABUCustomSplashAdapter>_Nonnull)adapter;

/// 在广告视频播放完成或者出错时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 播放错误
- (void)splashAd:(id<ABUCustomSplashAdapter>_Nonnull)adapter didPlayFinishWithError:(NSError *)error;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end

/// 开屏广告zoom out 视图协议
@protocol ABUCustomSplashAdapterZoomOutViewBridge <NSObject>

/// 当zoom out 视图点击时调用，直接调用即可，无需做响应判断
/// @param splashZoomOutView zoom out 视图
- (void)adapterAdSplashZoomOutViewDidClick:(UIView *_Nonnull)splashZoomOutView;

/// 当zoom out 视图关闭时调用，直接调用即可，无需做响应判断
/// @param splashZoomOutView zoom out 视图
- (void)adapterAdSplashZoomOutViewDidClose:(UIView *_Nonnull)splashZoomOutView;

/// 当zoom out 在广告已经展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param splashZoomOutView zoom out 视图
- (void)adapterAdSplashZoomOutViewDidPresentFullScreenModal:(UIView *_Nonnull)splashZoomOutView;

/// 当zoom out 在广告已经关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param splashZoomOutView zoom out 视图
- (void)adapterAdSplashZoomOutViewDidDismissFullScreenModal:(UIView *_Nonnull)splashZoomOutView;

@end

/// 开屏广告cardView 视图协议
@protocol ABUCustomSplashAdapterCardViewBridge <NSObject>

/// 当zoom out 视图点击时调用，直接调用即可，无需做响应判断
/// @param splashCardView cardView 视图
- (void)adapterAdSplashCardViewDidClick:(UIView *_Nonnull)splashCardView;

/// 当zoom out 视图关闭时调用，直接调用即可，无需做响应判断
/// @param splashCardView cardView 视图
- (void)adapterAdSplashCardViewDidClose:(UIView *_Nonnull)splashCardView;

/// 当zoom out 在广告已经展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param splashCardView cardView 视图
- (void)adapterAdSplashCardViewDidPresentFullScreenModal:(UIView *_Nonnull)splashCardView;

/// 当zoom out 在广告已经关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param splashCardView cardView 视图
- (void)adapterAdSplashCardViewDidDismissFullScreenModal:(UIView *_Nonnull)splashCardView;

@end

NS_ASSUME_NONNULL_END
