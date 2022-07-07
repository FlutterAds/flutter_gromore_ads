package com.zero.flutter_gromore_ads.page;

import android.util.Log;

import androidx.annotation.NonNull;

import com.bytedance.msdk.api.AdError;
import com.bytedance.msdk.api.reward.RewardItem;
import com.bytedance.msdk.api.v2.GMAdConstant;
import com.bytedance.msdk.api.v2.ad.fullvideo.GMFullVideoAd;
import com.bytedance.msdk.api.v2.ad.fullvideo.GMFullVideoAdListener;
import com.bytedance.msdk.api.v2.ad.fullvideo.GMFullVideoAdLoadCallback;
import com.bytedance.msdk.api.v2.slot.GMAdOptionUtil;
import com.bytedance.msdk.api.v2.slot.GMAdSlotFullVideo;
import com.zero.flutter_gromore_ads.event.AdEventAction;

import io.flutter.plugin.common.MethodCall;

/**
 * 全屏视频广告
 */
public class FullVideoPage extends BaseAdPage implements GMFullVideoAdLoadCallback, GMFullVideoAdListener {
    private final String TAG = FullVideoPage.class.getSimpleName();
    private GMFullVideoAd ad;

    @Override
    public void loadAd(@NonNull MethodCall call) {
        int orientation = call.argument("orientation");

        ad = new GMFullVideoAd(activity, this.posId);
        GMAdSlotFullVideo adSlot = new GMAdSlotFullVideo.Builder()
                .setGMAdSlotGDTOption(GMAdOptionUtil.getGMAdSlotGDTOption().build())
                .setGMAdSlotBaiduOption(GMAdOptionUtil.getGMAdSlotBaiduOption().build())
                .setUserID("user123")//用户id,必传参数
                .setOrientation(orientation)//必填参数，期望视频的播放方向：TTAdConstant.HORIZONTAL 或 TTAdConstant.VERTICAL;
                .build();
        ad.loadAd(adSlot, this);
    }

    @Override
    public void onFullVideoLoadFail(@NonNull AdError adError) {
        Log.e(TAG, "onFullVideoLoadFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onFullVideoAdLoad() {
        Log.i(TAG, "onFullVideoAdLoad");
        // 添加广告事件
        sendEvent(AdEventAction.onAdLoaded);
        // 显示广告
        if (ad != null && ad.isReady()) {
            ad.setFullVideoAdListener(this);
            ad.showFullAd(activity);
        }
    }

    @Override
    public void onFullVideoAdShow() {
        Log.i(TAG, "onFullVideoAdShow");
        // 添加广告事件
        sendEvent(AdEventAction.onAdExposure);
    }

    @Override
    public void onFullVideoAdShowFail(@NonNull AdError adError) {
        Log.e(TAG, "onFullVideoAdShowFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onFullVideoAdClick() {
        Log.i(TAG, "onFullVideoAdClick");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClicked);
    }

    @Override
    public void onFullVideoAdClosed() {
        Log.i(TAG, "onFullVideoAdClosed");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClosed);
        if (ad != null) {
            ad.destroy();
            ad = null;
        }
    }

    @Override
    public void onVideoComplete() {
        Log.i(TAG, "onVideoComplete");
        // 添加广告事件
        sendEvent(AdEventAction.onAdComplete);
    }

    @Override
    public void onVideoError() {
        Log.i(TAG, "onVideoError");
        // 添加广告事件
        sendErrorEvent(-200, "onVideoError");
    }

    @Override
    public void onSkippedVideo() {
        Log.i(TAG, "onSkippedVideo");
        // 添加广告事件
        sendEvent(AdEventAction.onAdSkip);
    }

    @Override
    public void onRewardVerify(@NonNull RewardItem rewardItem) {

    }

    @Override
    public void onFullVideoCached() {
        Log.i(TAG, "onFullVideoCached");
    }
}