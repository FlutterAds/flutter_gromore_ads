//
// Created by bytedance on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import "ABUMediatedNativeAdData.h"
#import "ABUMediatedNativeAdViewCreator.h"

@interface ABUMediatedNativeAd : NSObject

// 广告物料，包含有最全的广告数据
@property (nonatomic, strong, nonnull) id<ABUMediatedNativeAdData> data;

// 广告视图创建对象，对常用广告展示元素进行创建（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) id<ABUMediatedNativeAdViewCreator> viewCreator;

// 广告视图对象（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) UIView *view;

// adn获取到的原始广告数据
@property (nonatomic, strong, nonnull) id originMediatedNativeAd;

@end
