//
//  ABUCustomAdapterVersion.h
//  ABUAdSDK
//
//  Created by bytedance on 2021/9/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ABUCustomAdapterVersion;

/// 自定义adapter协议版本，版本号 1.0
extern ABUCustomAdapterVersion * const ABUCustomAdapterVersion1_0;
/// 自定义adapter协议版本，版本号 1.1
extern ABUCustomAdapterVersion * const ABUCustomAdapterVersion1_1;

/// 自定义adapter使用的协议版本，请开发者实现/更新自定义adapter时使用最新版本的版本号即可
/// GroMore会根据实际情况控制adapter是否可用，[及时更新]
@interface ABUCustomAdapterVersion : NSString @end

NS_ASSUME_NONNULL_END
