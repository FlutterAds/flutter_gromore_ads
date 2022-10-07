//
//  ABUCustomAdapter.h
//  ABUAdSDK
//
//  Created by Makaiwen on 2021/5/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ABUCustomConfigAdapter;
@class ABUMediaBidResult;

typedef NS_ENUM(NSInteger, ABUMediatedAdStatusValue) {
    ABUMediatedAdStatusValueDeny = -1,
    ABUMediatedAdStatusValueUnknown = 0,
    ABUMediatedAdStatusValueSure = 1,
};

/// adn广告状态
typedef struct {
    ABUMediatedAdStatusValue isReady;
    ABUMediatedAdStatusValue unexpired;
    ABUMediatedAdStatusValue valid;
} ABUMediatedAdStatus;

extern const ABUMediatedAdStatus ABUMediatedAdStatusUnknown;

extern const ABUMediatedAdStatus ABUMediatedAdStatusNormal;

static inline
BOOL ABUMediatedAdStatusEqualsTo(ABUMediatedAdStatus aStatus, ABUMediatedAdStatus anotherStatus) {
    return aStatus.isReady == anotherStatus.isReady &&
        aStatus.unexpired == anotherStatus.unexpired &&
        aStatus.valid == anotherStatus.valid;
}

static inline
ABUMediatedAdStatus ABUMediatedAdStatusMake(ABUMediatedAdStatusValue isReady, ABUMediatedAdStatusValue unexpired, ABUMediatedAdStatusValue valid) {
    ABUMediatedAdStatus status = {ABUMediatedAdStatusValueUnknown, ABUMediatedAdStatusValueUnknown , ABUMediatedAdStatusValueUnknown};
    status.isReady = isReady;
    status.unexpired = unexpired;
    status.valid = valid;
    return status;
}

/// 自定义adapter广告类型基本协议
@protocol ABUCustomAdapter <NSObject>
@optional

- (NSString *)serverBiddingTokenWithParams:(NSDictionary *)params error:(NSError **)error;

/// 需要传递token以外值时,使用此方法
- (NSString *)serverBiddingTokenWithParams:(NSDictionary *)params otherInfo:(NSMutableDictionary *)otherInfo error:(NSError **)error;

/// 当前广告有广告正在展示时是否允许进行预加载广告，未实现则为NO。
- (BOOL)enablePreloadWhenCurrentIsDisplay;

/// 回调客户端竞价结果，比价成功时回传成功，比价失败、返回超时或价格低于竞价底价时回传失败
/// @param result bid结果对象
/// @warning 1.创建广告时需设置bidNotify属性为YES才会触发该回调
///          2.adn广告load失败不触发该回调，如需回传adn竞价结果，请在load失败处自行处理
///          3.信息流加载多条会触发多次，返回每条比价结果
- (void)didReceiveBidResult:(nonnull ABUMediaBidResult *)result;

/// 开发者无需实现，系统自动生成
@property (nonatomic, assign) BOOL isCustomAdapter;

/// 开发者无需实现，系统自动生成
@property (nonatomic, strong) id<ABUCustomConfigAdapter> configAdapter;

@end

@protocol ABUBaseCustomAdapter <ABUCustomAdapter>

- (id)bridge;

@end

NS_ASSUME_NONNULL_END
