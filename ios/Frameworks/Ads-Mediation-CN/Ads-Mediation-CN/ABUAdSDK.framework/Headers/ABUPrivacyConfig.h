//
//  ABUPrivacyConfig.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/8/24.
//

#import <Foundation/Foundation.h>

/// 【可选】NSNumber，是否限制个性化广告:0-不限制，1-限制，默认为0。官方维护版本中只适用于CSJ、Ks、Sigmob、百度、GDT。
const static NSString *kABUPrivacyLimitPersonalAds = @"ABUPrivacyLimitPersonalAds";

/// 【可选】NSNumber，是否限制程序化广告:0-不限制，1-限制，默认为0。官方维护版本中只适用于Ks。
const static NSString *kABUPrivacyLimitProgrammaticAds = @"ABUPrivacyLimitProgrammaticAds";

/// 【可选】NSNumber，是否禁止CAID：0-不禁止，1-禁止，默认为0。官方维护版本中只适用于百度。
const static NSString *kABUPrivacyForbiddenCAID = @"ABUPrivacyForbiddenCAID";

/// 【可选】NSNumber，是否禁止IDFA：0-不禁止，1-禁止，默认为0。官方维护版本中只适用于GDT。
const static NSString *kABUPrivacyForbiddenIDFA = @"ABUPrivacyForbiddenIDFA";

/// 【可选】NSNumber，是否在adn中使用位置，如果是，adn将自己获得纬度和经度，而不是使用传入的值（kABUPrivacyLongitude/kABUPrivacyLatitude）。官方维护版本中只适用于CSJ。
const static NSString *kABUPrivacyCanLocation = @"ABUPrivacyCanLocation";

/// 【可选】NSNumber，经度的值。默认值是0.0。官方维护版本中只适用于CSJ。
const static NSString *kABUPrivacyLongitude = @"ABUPrivacyLongitude";

/// 【可选】NSNumber，纬度的值。默认值是0.0。官方维护版本中只适用于CSJ。
const static NSString *kABUPrivacyLatitude = @"ABUPrivacyLatitude";

/// 【可选】NSNumber，是成人或者儿童，2-儿童(＜15),1-儿童(15-18岁), 0-成人，默认为0(成人)。官方维护版本中适用于CSJ/sigmob。
const static NSString *kABUPrivacyNotAdult = @"ABUPrivacyNotAdult";


@interface ABUPrivacyConfig : NSObject

// 根据key配置相关隐私项
+ (void)setPrivacyWithKey:(const NSString *)key andValue:(id)value;

// 获取当前配置项
+ (NSDictionary *)privacyConfig;

@end

