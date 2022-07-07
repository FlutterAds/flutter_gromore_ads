//
//  ABUCustomSplashAdapter.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/6/8.
//

#import <Foundation/Foundation.h>
#import "ABUCustomAdapter.h"
#import "ABUCustomSplashAdapterBridge.h"

NS_ASSUME_NONNULL_BEGIN

/// 开屏广告自定义实现协议
@protocol ABUCustomSplashAdapter <ABUCustomAdapter>

/// 加载开屏广告
/// @param slotID 广告位ID
/// @param parameter 广告加载参数
- (void)loadSplashAdWithSlotID:(NSString *)slotID andParameter:(NSDictionary *)parameter;

/// 展示开屏广告
/// @param window 广告展示窗口
/// @param parameter 广告展示参数
- (void)showSplashAdInWindow:(UIWindow *)window parameter:(NSDictionary *)parameter;

/// 广告关闭实现，在外部使用开发者调用`destoryAd`时触发
- (void)dismissSplashAd;

/// 当前加载的广告的状态
- (ABUMediatedAdStatus)mediatedAdStatus;

@optional

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<ABUCustomSplashAdapterBridge, ABUCustomSplashAdapterZoomOutViewBridge, ABUCustomSplashAdapterCardViewBridge> bridge;

/// 展示开屏cardView
/// @param rootVC cardView要展示在的VC
/// @param parameter 额外参数
- (void)showSplashCardInRootVC:(UIViewController *)rootVC parameter:(NSDictionary *)parameter;

@end

NS_ASSUME_NONNULL_END
