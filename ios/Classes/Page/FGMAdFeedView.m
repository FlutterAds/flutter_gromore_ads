//
//  FGMAdFeedView.m
//  flutter_gromore_ads
//
//  Created by Zero on 2023/2/3.
//

#import "FGMAdFeedView.h"
//
//@interface FGMAdFeedView()<FlutterPlatformView,ABUNativeAdViewDelegate,ABUNativeAdVideoDelegate>
//@property (strong,nonatomic) UIView *feedView;
//@property (strong,nonatomic) ABUNativeAdView *adView;
//@property (strong,nonatomic) FlutterMethodChannel *methodChannel;
//@end
//
//@implementation FGMAdFeedView
//
//- (instancetype)initWithFrame:(CGRect)frame viewIdentifier:(int64_t)viewId arguments:(id)args binaryMessenger:(NSObject<FlutterBinaryMessenger> *)messenger plugin:(FlutterGromoreAdsPlugin *)plugin{
//    if(self==[super init]){
//        self.viewId=viewId;
//        self.feedView =[[UIView alloc] init];
//        self.methodChannel = [FlutterMethodChannel methodChannelWithName:[NSString stringWithFormat:@"%@/%lli",kGMAdFeedViewId,viewId] binaryMessenger:messenger];
//        FlutterMethodCall *call= [FlutterMethodCall methodCallWithMethodName:@"AdFeedView" arguments:args];
//        [self showAd:call eventSink:plugin.eventSink];
//    }
//    NSLog(@"%s %lli",__FUNCTION__,viewId);
//    return self;
//}
//
//- (UIView *)view{
//    return self.feedView;
//}
//
//- (void)dealloc{
//    NSLog(@"%s",__FUNCTION__);
//}
//
//- (void)loadAd:(FlutterMethodCall *)call{
//    NSNumber *key=[NSNumber numberWithInteger:[self.posId integerValue]];
//    self.adView=[FGMFeedAdManager.share getAd:key];
//    self.adView.delegate=self;
//    self.adView.videoDelegate=self;
//    [self.feedView addSubview:self.adView];
//    [self.adView render];
//}
//
//// 处理消息
//- (void) postMsghandler:(NSString*) event{
//    NSLog(@"%s postMsghandler event:%@",__FUNCTION__,event);
//    if([event isEqualToString:onAdExposure]){
//        // 渲染成功，设置高度
//        CGSize size= self.feedView.frame.size;
//        [self setFlutterViewSize:size];
//    }else if([event isEqualToString:onAdClosed]){
//        self.adView.delegate = nil;
//        // 广告关闭移除广告，并且设置大小为 0，隐藏广告
//        [self.adView removeFromSuperview];
//        [self setFlutterViewSize:CGSizeZero];
//    }
//}
//// 设置 FlutterAds 视图宽高
//- (void) setFlutterViewSize:(CGSize) size{
//    NSNumber *width=[NSNumber numberWithFloat:size.width];
//    NSNumber *height=[NSNumber numberWithFloat:size.height];
//    NSDictionary *dicSize=[NSDictionary dictionaryWithObjects:[NSArray arrayWithObjects:width,height, nil] forKeys:[NSArray arrayWithObjects:@"width",@"height", nil]];
//    self.adView.center=self.feedView.center;
//    [self.methodChannel invokeMethod:@"setSize" arguments:dicSize];
//}
//
//
//- (void)nativeAdExpressViewRenderFail:(ABUNativeAdView *)nativeExpressAdView error:(NSError *)error{
//    NSLog(@"%s",__FUNCTION__);
//    // 发送广告错误事件
//    [self sendErrorEvent:error];
//    [self postMsghandler:onAdClosed];
//}
//
//- (void)nativeAdDidBecomeVisible:(ABUNativeAdView *)nativeAdView{
//    NSLog(@"%s",__FUNCTION__);
//    // 发送广告事件
//    [self sendEventAction:onAdExposure];
//    [self postMsghandler:onAdExposure];
//}
//
//- (void)nativeAdDidClick:(ABUNativeAdView *)nativeAdView withView:(UIView *)view{
//    NSLog(@"%s",__FUNCTION__);
//    // 发送广告事件
//    [self sendEventAction:onAdClicked];
//}
//
//
//
//- (void)nativeExpressAdViewWillShow:(ABUNativeAdView *)nativeExpressAdView{
//    NSLog(@"%s",__FUNCTION__);
//    // 发送广告事件
//    [self sendEventAction:onAdExposure];
//}
//
//- (void)nativeAdExpressViewDidClosed:(ABUNativeAdView *)nativeAdView closeReason:(NSArray<NSDictionary *> *)filterWords{
//    NSLog(@"%s",__FUNCTION__);
//    NSNumber *key=[NSNumber numberWithInteger:[nativeAdView hash]];
//    // 删除广告缓存
//    [FGMFeedAdManager.share removeAd:key];
//    // 发送广告事件
//    [self sendEventAction:onAdClosed];
//    // 关闭广告
//    [self postMsghandler:onAdClosed];
//}
//
//- (void)nativeExpressAdViewDidRemoved:(ABUNativeAdView *)nativeExpressAdView{
//    NSLog(@"%s",__FUNCTION__);
//}
//
//@end
