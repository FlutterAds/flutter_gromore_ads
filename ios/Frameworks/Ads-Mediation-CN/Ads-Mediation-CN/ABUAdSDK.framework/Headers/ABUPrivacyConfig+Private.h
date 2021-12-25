//
//  ABUPrivacyConfig+Private.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/8/24.
//

#import "ABUPrivacyConfig.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ABUCustomConfigAdapter;

@interface ABUPrivacyConfig (Private)

+ (instancetype _Nonnull)sharedInstance;

@end

NS_ASSUME_NONNULL_END
