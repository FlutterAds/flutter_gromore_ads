//
//  ABUAdapterRewardAdInfo.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 验证失败的原因----string
extern NSString *const ABUAdapterRewardAdCustomDataReasonKey;

/// 无法完成验证的错误码----number
extern NSString *const ABUAdapterRewardAdCustomDataErrorCodeKey;

/// 无法完成验证的错误原因----string，包括网络错误、服务端无响应、服务端无法验证等
extern NSString *const ABUAdapterRewardAdCustomDataErrorMsgKey;

/// 奖励类型，0:基础奖励 1:进阶奖励-互动 2:进阶奖励-超过30s的视频播放完成----number
/// 目前支持返回该字段的adn：csj
/// @warning: GroMore的S2S的验证暂不支持
extern NSString *const ABUAdapterRewardAdCustomDataRewardTypeKey;

/// 建议奖励百分比， 基础奖励为1，进阶奖励为0.0 ~ 1.0，开发者自行换算----number
/// 目前支持返回该字段的adn：csj
/// @warning: GroMore的S2S的验证暂不支持
extern NSString *const ABUAdapterRewardAdCustomDataRewardProposeKey;


/// 激励视频奖励信息，适用于ADN的奖励验证和GroMore的S2S奖励验证
@interface ABUAdapterRewardAdInfo : NSObject

/// adn定义的奖励id
@property (nonatomic, copy, nullable) NSString *rewardId;

/// 发放奖励的名称
@property (nonatomic, copy, nullable) NSString *rewardName;

/// 发放奖励的金额
@property (nonatomic, assign) NSInteger rewardAmount;

/// 交易的唯一标识
@property (nonatomic, copy, nullable) NSString *tradeId;

/// 是否验证通过
@property (nonatomic, assign) BOOL verify;

/// 验证奖励发放的媒体名称，官方支持的ADN名称详见`ABUAdnType`注释部分，自定义ADN名称同平台配置
@property (nonatomic, copy, nullable) NSString *adnName;

/// 验证奖励发放的ecpm，实际返回受规则限制
@property (nonatomic, copy, nullable) NSString *ecpm;

/// 其他数据信息，包括但不限于错误信息，固定字段定义见文件上方
@property (nonatomic, copy, nullable) NSDictionary *customData;

/// 是否是通过GroMore的S2S的验证
- (BOOL)verifyByGroMoreS2S;

@end

NS_ASSUME_NONNULL_END
