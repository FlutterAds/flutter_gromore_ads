//
//  ABURitInfo+Private.h
//  ABUAdSDK
//
//  Created by CHAORS on 2021/10/27.
//

#import "ABURitInfo.h"

@class ABUAdPackage;

NS_ASSUME_NONNULL_BEGIN

@interface ABURitInfo (Private)

- (instancetype)initWithAdPackage:(ABUAdPackage *)package withLoadPrice:(NSString *)loadPrice;

@end

NS_ASSUME_NONNULL_END
