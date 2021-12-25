//
//  ABUCustomBannerAdapter.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/27.
//

#import <Foundation/Foundation.h>
#import "ABUCustomAdapter.h"
#import "ABUCustomBannerAdapterBridge.h"

NS_ASSUME_NONNULL_BEGIN

/// 自定义banner广告adapter协议
@protocol ABUCustomBannerAdapter <ABUCustomAdapter>

/// 必要，加载banner广告方法
/// @param slotID adn的广告位ID
/// @param adSize 广告展示尺寸
/// @param parameter 广告加载参数
- (void)loadBannerAdWithSlotID:(NSString *)slotID andSize:(CGSize)adSize parameter:(nullable NSDictionary *)parameter;

@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<ABUCustomBannerAdapterBridge> bridge;

@end

NS_ASSUME_NONNULL_END
