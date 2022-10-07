//
//  ABUDictionary.h
//  Ads-Mediation-CN
//
//  Created by bytedance on 2022/8/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 隐藏信息的字典，可以隐藏部分key的键值，不过可以通过key获取
@interface ABUDictionary : NSDictionary

// array 为字典中正常显示的内容
+ (instancetype)dictionaryWithDictionary:(NSDictionary *)dict array:(NSArray *)array;

@end

NS_ASSUME_NONNULL_END
