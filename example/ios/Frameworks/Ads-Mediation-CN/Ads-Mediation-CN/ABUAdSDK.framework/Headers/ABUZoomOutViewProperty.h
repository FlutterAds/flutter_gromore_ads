//
//  ABUZoomOutViewProperty.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/9/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 开屏点睛处理时机
typedef NS_ENUM (NSInteger, ABUAddOccasionType) {
    ABUAddOccasionTypeWhenLoad = 0,       // 需要在load回调里处理开屏点睛视图ABUSplashZoomOutView，eg:gdt
    ABUAddOccasionTypeWhenClose,          // 需要在close回调里处理开屏点睛视图ABUSplashZoomOutView，eg:pangle
};

/// 开屏点睛属性类
@interface ABUZoomOutViewProperty : NSObject

/// 点睛的展示尺寸
@property (nonatomic, assign) CGSize size;

/// 是否自己有动画
@property (nonatomic, assign) BOOL hasAnimation;

/// 处理时机
@property (nonatomic, assign) ABUAddOccasionType addOccasionType;
@end

NS_ASSUME_NONNULL_END
