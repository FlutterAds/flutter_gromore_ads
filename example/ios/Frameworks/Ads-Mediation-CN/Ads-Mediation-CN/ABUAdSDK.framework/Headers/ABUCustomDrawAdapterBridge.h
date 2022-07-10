//
//  ABUCustomDrawAdapterBridge.h
//  Ads-Mediation-CN
//
//  Created by heyinyin on 2022/3/31.
//

#import <Foundation/Foundation.h>
#import "ABUMediatedNativeAd.h"
#import "ABUPlayerPlayState.h"

NS_ASSUME_NONNULL_BEGIN
@protocol ABUCustomDrawAdapter;

/// 自定义Draw视频广告的adapter的回调协议
@protocol ABUCustomDrawAdapterBridge <NSObject>

@optional
/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ads 广告数据组  模板为视图类型数组，非模板为ABUMediatedNativeAd类型数组
/// @param exts 扩展信息组  key值请参照ABUMediaAdLoadingExt*****，与ads一一对应
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didLoadWithDrawAds:(NSArray *_Nullable)ads exts:(NSArray<NSDictionary *> * _Nullable)exts;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;

#pragma mark - View

/// 广告展示时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didVisibleWithMediatedAd:(id _Nonnull)drawAd;

/// 广告点击事件时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didClickWithMediatedAd:(id _Nonnull)drawAd;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter willPresentFullScreenModalWithMediatedAd:(id _Nonnull)drawAd;

/// 在广告关闭详情页或者appstore时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter willDismissFullScreenModalWithMediatedAd:(id _Nonnull)drawAd;

/// 仅限自渲染广告，在广告关闭的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd）
/// @param filterWords 用户手动关闭时的关闭原因描述
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didCloseWithMediatedAd:(id _Nonnull)drawAd closeReasons:(NSArray<ABUDislikeWords *> *_Nullable)filterWords;

#pragma mark - Express ad
/// 仅限模板广告，在渲染成功或者模板广告的尺寸更新时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter renderSuccessWithExpressView:(UIView *_Nonnull)expressView;

/// 仅限模板广告，在渲染失败调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter renderFailWithExpressView:(UIView *_Nonnull)expressView andError:(NSError *_Nonnull)error;

/// 仅限模板广告，在模板广告关闭的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param expressView 模板广告请传递上报expressView
/// @param filterWords 用户手动关闭时的关闭原因描述
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter didCloseWithExpressView:(UIView *_Nonnull)expressView closeReasons:(NSArray<ABUDislikeWords *> *_Nullable)filterWords;
#pragma mark - video

/// 视频广告中视频播放状态变更的时候调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param state 播放状态
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter videoStateDidChangedWithState:(ABUPlayerPlayState)state andMediatedAd:(id _Nonnull)drawAd;

/// 视频广告中视频视图被点击时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter videoDidClick:(id _Nonnull)drawAd;

/// 视频广告中视频播放完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param drawAd 自渲染广告请传递原始数据（即ABUMediatedNativeAd.originMediatedNativeAd），模板广告请传递上报expressView
- (void)drawAd:(id<ABUCustomDrawAdapter>_Nonnull)adapter videoDidPlayFinish:(id _Nonnull)drawAd;
@end

NS_ASSUME_NONNULL_END
