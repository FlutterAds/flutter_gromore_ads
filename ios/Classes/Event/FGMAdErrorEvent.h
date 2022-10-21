//
//  FGMAdErrorEvent.h
//  flutter_gromore_ads
//
//  Created by zero on 2021/12/11.
//

#import "FGMAdEvent.h"

// 广告错误事件
@interface FGMAdErrorEvent : FGMAdEvent
// 错误码
@property (assign,nonatomic) NSInteger errCode;
// 错误信息
@property (copy,nonatomic) NSString *errMsg;

-(id) initWithAdId:(NSString *)adId errCode:(NSInteger)errCode errMsg:(NSString*) errMsg;
-(id) initWithAdId:(NSString *)adId error:(NSError *)error;
@end
