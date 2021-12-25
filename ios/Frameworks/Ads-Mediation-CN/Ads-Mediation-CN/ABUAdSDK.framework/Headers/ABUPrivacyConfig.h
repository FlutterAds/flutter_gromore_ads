//
//  ABUPrivacyConfig.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/8/24.
//

#import <Foundation/Foundation.h>

/// optional key. Whether to restrict personalized ads:0-not limit, 1-limit, the default is 0.Now only valid for pangle, Ks, Sigmob and Baidu adn.
const static NSString *kABUPrivacyLimitPersonalAds = @"ABUPrivacyLimitPersonalAds";
/// optional key. Whether to restrict programmatic ads:0-not limit, 1-limit, the default is 0.Now only valid for Ks adn.
const static NSString *kABUPrivacyLimitProgrammaticAds = @"ABUPrivacyLimitProgrammaticAds";
/// optional key. Whether to forbid CAID:0-not forbidden, 1-forbid, the default is 0.Now only valid for pangle Baidu adn.
const static NSString *kABUPrivacyForbiddenCAID = @"ABUPrivacyForbiddenCAID";
/// optional key. Whether to use location in adn SDK. If yes adn SDK will get the latitude and longitude by itself instead of using the passed in value(kABUPrivacyLongitude/kABUPrivacyLatitude). Now only valid for pangle adn.
const static NSString *kABUPrivacyCanLocation = @"ABUPrivacyCanLocation";
/// optional key. The value of longitude & latitude.The default is 0.0. Now only valid for pangle adn.
const static NSString *kABUPrivacyLongitude = @"ABUPrivacyLongitude";
const static NSString *kABUPrivacyLatitude = @"ABUPrivacyLatitude";
/// optional key. Whether to be a adult or children:1-children, 0-adult, the default is 0(adult).Now only valid for sigmob adn.
const static NSString *kABUPrivacyNotAdult = @"ABUPrivacyNotAdult";


@interface ABUPrivacyConfig : NSObject

// 根据key配置相关隐私项
+ (void)setPrivacyWithKey:(const NSString *)key andValue:(id)value;

// 获取当前配置项
+ (NSDictionary *)privacyConfig;

@end

