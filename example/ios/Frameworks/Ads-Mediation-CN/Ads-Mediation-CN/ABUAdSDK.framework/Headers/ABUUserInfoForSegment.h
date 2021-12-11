//
//  ABUUserInfoForSegment.h
//  ABUAdSDK
//
//  Created by heyinyin on 2021/2/25.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, ABUUserInfoGender) {
    ABUUserInfoGenderFemale                   = 0,
    ABUUserInfoGenderMale                     = 1,
    ABUUserInfoGenderUnknown                  = 2,
    ABUUserInfoGenderUnSet                    = 3 //default，can't use.
};

// 兼容旧版本
typedef ABUUserInfoGender ABUUserInfo_Gender;
#define ABUUserInfo_Gender_Female ABUUserInfoGenderFemale
#define ABUUserInfo_Gender_Male ABUUserInfoGenderMale
#define ABUUserInfo_Gender_Unknown ABUUserInfoGenderUnknown
#define ABUUserInfo_Gender_UnSet ABUUserInfoGenderUnSet

/// 流量分组信息
@interface ABUUserInfoForSegment : NSObject
/// user_id
@property (nonatomic, copy) NSString *user_id;
/// 渠道
@property (nonatomic, copy) NSString *channel;
/// 子渠道
@property (nonatomic, copy) NSString *sub_channel;
/// 用户年龄
@property (nonatomic, assign) NSInteger age;
/// 用户性别
@property (nonatomic, assign) ABUUserInfoGender gender;
/// 价值分组
@property (nonatomic, copy) NSString *user_value_group;

/// 自定义设置
/**
 要求:
    自定义参数key&value要求均为string
    字符为数字,字母,"-","_"任意组合
    长度上限为100
 */
@property (nonatomic, copy) NSDictionary *customized_id;
@end

