package com.zero.flutter_gromore_ads.page;

import android.util.Log;

import androidx.annotation.NonNull;

import com.bytedance.msdk.api.AdError;
import com.bytedance.msdk.api.v2.GMAdConstant;
import com.bytedance.msdk.api.v2.ad.interstitialFull.GMInterstitialFullAd;
import com.bytedance.msdk.api.v2.ad.interstitialFull.GMInterstitialFullAdListener;
import com.bytedance.msdk.api.v2.ad.interstitialFull.GMInterstitialFullAdLoadCallback;
import com.bytedance.msdk.api.v2.slot.GMAdOptionUtil;
import com.bytedance.msdk.api.v2.slot.GMAdSlotInterstitialFull;
import com.zero.flutter_gromore_ads.event.AdEventAction;

import io.flutter.plugin.common.MethodCall;

/**
 * 全屏插屏广告
 */
public class InterstitialFullPage extends BaseAdPage implements GMInterstitialFullAdLoadCallback, GMInterstitialFullAdListener {
    private final String TAG = InterstitialFullPage.class.getSimpleName();
    private GMInterstitialFullAd ad;

    @Override
    public void loadAd(@NonNull MethodCall call) {
        int width = call.argument("width");
        int height = call.argument("height");
        ad = new GMInterstitialFullAd(activity, this.posId);
        GMAdSlotInterstitialFull adSlot = new GMAdSlotInterstitialFull.Builder()
                .setGMAdSlotBaiduOption(GMAdOptionUtil.getGMAdSlotBaiduOption().build())
                .setGMAdSlotGDTOption(GMAdOptionUtil.getGMAdSlotGDTOption().build())
                .setImageAdSize(width, height)  //设置宽高 （插全屏类型下_插屏广告使用）
                .setVolume(0.5f) //admob 声音配置，与setMuted配合使用
                .setUserID("user123")//用户id,必传参数 (插全屏类型下_全屏广告使用)
                .setOrientation(GMAdConstant.VERTICAL)//必填参数，期望视频的播放方向：TTAdConstant.HORIZONTAL 或 TTAdConstant.VERTICAL; (插全屏类型下_全屏广告使用)
                .build();
        ad.loadAd(adSlot, this);
    }

    @Override
    public void onInterstitialFullLoadFail(@NonNull AdError adError) {
        Log.e(TAG, "onInterstitialLoadFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onInterstitialFullAdLoad() {
        Log.i(TAG, "onInterstitialLoad");
        // 添加广告事件
        sendEvent(AdEventAction.onAdLoaded);
        // 设置监听

        if (ad != null && ad.isReady()) {
            ad.setAdInterstitialFullListener(this);
            ad.showAd(activity);
        }
    }

    @Override
    public void onInterstitialFullShow() {
        Log.i(TAG, "onInterstitialFullShow");
        // 添加广告事件
        sendEvent(AdEventAction.onAdExposure);
    }

    @Override
    public void onInterstitialFullShowFail(@NonNull AdError adError) {
        Log.e(TAG, "onInterstitialLoadFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onInterstitialFullClick() {
        Log.i(TAG, "onInterstitialFullClick");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClicked);
    }

    @Override
    public void onInterstitialFullClosed() {
        Log.i(TAG, "onInterstitialFullClosed");
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
        Log.i(TAG, "onVideoComplete");
        // 添加广告事件
        sendEvent(AdEventAction.onAdComplete);
    }

    @Override
    public void onAdOpened() {
        Log.i(TAG, "onAdOpened");
    }

    @Override
    public void onAdLeftApplication() {
        Log.i(TAG, "onAdLeftApplication");
    }

    @Override
    public void onInterstitialFullCached() {
        Log.i(TAG, "onInterstitialFullCached");
    }
}