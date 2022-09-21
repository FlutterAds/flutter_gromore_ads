//
//  ABUCustomNativeAdapter.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import <Foundation/Foundation.h>
#import "ABUCustomAdapter.h"
#import "ABUCustomNativeAdapterBridge.h"
#import "ABUVideoAdReportSupport.h"

NS_ASSUME_NONNULL_BEGIN

@class ABUDislikeReason;

/// 自定义Native广告的adapter广告协议
@protocol ABUCustomNativeAdapter <ABUCustomAdapter>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param size 广告展示尺寸
/// @param imageSize 图片或视频展示尺寸
/// @param parameter 广告加载的参数
- (void)loadNativeAdWithSlotID:(NSString *)slotID andSize:(CGSize)size imageSize:(CGSize)imageSize parameter:(NSDictionary *)parameter;

/// 渲染广告，为模板广告时会回调该方法，需对广告进行渲染
/// @param expressAdView 模板广告
- (void)renderForExpressAdView:(UIView *)expressAdView;

/// 为模板广告设置控制器
/// @param viewController 控制器
/// @param expressAdView 模板广告
- (void)setRootViewController:(UIViewController *)viewController forExpressAdView:(UIView *)expressAdView;

/// 为非模板广告设置控制器
/// @param viewController 控制器
/// @param nativeAd 非模板广告
- (void)setRootViewController:(UIViewController *)viewController forNativeAd:(id)nativeAd;

/// 注册容器和可点击区域
/// @param containerView 容器视图
/// @param views 可点击视图组
- (void)registerContainerView:(__kindof UIView *)containerView andClickableViews:(NSArray<__kindof UIView *> *)views forNativeAd:(id)nativeAd;

@optional

/// 当前加载的广告的状态，native模板广告
- (ABUMediatedAdStatus)mediatedAdStatusWithExpressView:(UIView *)view;

/// 当前加载的广告的状态，native非模板广告
- (ABUMediatedAdStatus)mediatedAdStatusWithMediatedNativeAd:(ABUMediatedNativeAd *)ad;

/// 广告视图即将被展示回调，只会调用一次
/// @param expressAdView 模板广告视图
/// @param mediatedNativeAd GroMore包装的广告数据
- (void)adViewWillAddToSuperViewWithExpressAdView:(__kindof UIView *)expressAdView orMediatedNativeAd:(ABUMediatedNativeAd *)mediatedNativeAd;

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<ABUCustomNativeAdapterBridge> bridge;

/// 上报dislike的原因，仅限非模板广告自定义关闭按钮时使用
/// @param ad GroMore包装的非模板广告数据
/// @param reasons dislike的原因。数据基于ADN提供的原因修改
- (void)reportDislikeAd:(ABUMediatedNativeAd *)ad withReasons:(NSArray<ABUDislikeReason *> *)reasons;

- (void)reportVideoEvent:(ABUVideoAdEvent)event forAd:(ABUMediatedNativeAd *)ad withParameters:(NSDictionary *)parameters;

@end

NS_ASSUME_NONNULL_END
