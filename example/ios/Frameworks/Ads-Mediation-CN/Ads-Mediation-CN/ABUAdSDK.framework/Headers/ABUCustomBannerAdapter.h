//
//  ABUCustomBannerAdapter.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/27.
//

#import <Foundation/Foundation.h>
#import "ABUCustomAdapter.h"
#import "ABUCustomBannerAdapterBridge.h"
#import "ABUCustomNativeAdapter.h"
@protocol ABUCustomBannerMixNativeAdapter;

NS_ASSUME_NONNULL_BEGIN

/// 自定义banner广告adapter协议
@protocol ABUCustomBannerAdapter <ABUCustomAdapter, ABUCustomBannerMixNativeAdapter>

/// 必要，加载banner广告方法
/// @param slotID adn的广告位ID
/// @param adSize 广告展示尺寸
/// @param parameter 广告加载参数
- (void)loadBannerAdWithSlotID:(NSString *)slotID andSize:(CGSize)adSize parameter:(nullable NSDictionary *)parameter;

/// 当前加载的广告的状态
- (ABUMediatedAdStatus)mediatedAdStatus;

@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<ABUCustomBannerAdapterBridge> bridge;

@end

/// 当Banner广告位下混用信息流代码位，请实现如下协议方法
@protocol ABUCustomBannerMixNativeAdapter

@optional

/// 注册容器和可点击区域
/// @param containerView 容器视图
/// @param views 可点击视图组
- (void)registerContainerView:(__kindof UIView *)containerView andClickableViews:(NSArray<__kindof UIView *> *)views forNativeAd:(id)nativeAd;

@end



NS_ASSUME_NONNULL_END
