package com.zero.flutter_gromore_ads.page;

import android.util.Log;
import android.view.View;

import androidx.annotation.NonNull;

import com.bytedance.msdk.api.AdError;
import com.bytedance.msdk.api.v2.ad.interstitial.GMInterstitialAd;
import com.bytedance.msdk.api.v2.ad.interstitial.GMInterstitialAdListener;
import com.bytedance.msdk.api.v2.ad.interstitial.GMInterstitialAdLoadCallback;
import com.bytedance.msdk.api.v2.slot.GMAdOptionUtil;
import com.bytedance.msdk.api.v2.slot.GMAdSlotInterstitial;
import com.zero.flutter_gromore_ads.event.AdEventAction;

import io.flutter.plugin.common.MethodCall;

/**
 * 插屏广告
 */
public class InterstitialPage extends BaseAdPage implements GMInterstitialAdLoadCallback, GMInterstitialAdListener {
    private final String TAG = InterstitialPage.class.getSimpleName();
    private GMInterstitialAd ad;

    @Override
    public void loadAd(@NonNull MethodCall call) {
        int width = call.argument("width");
        int height = call.argument("height");
        ad = new GMInterstitialAd(activity, this.posId);
        GMAdSlotInterstitial adSlot = new GMAdSlotInterstitial.Builder()
                .setGMAdSlotBaiduOption(GMAdOptionUtil.getGMAdSlotBaiduOption().build())
                .setGMAdSlotGDTOption(GMAdOptionUtil.getGMAdSlotGDTOption().build())
                .setImageAdSize(width, height)
                .build();
        ad.loadAd(adSlot, this);
    }

    @Override
    public void onInterstitialLoadFail(@NonNull AdError adError) {
        Log.e(TAG, "onInterstitialLoadFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onInterstitialLoad() {
        Log.i(TAG, "onInterstitialLoad");
        // 添加广告事件
        sendEvent(AdEventAction.onAdLoaded);
        // 设置监听

        if (ad != null && ad.isReady()) {
            ad.setAdInterstitialListener(this);
            ad.showAd(activity);
        }
    }

    @Override
    public void onInterstitialShow() {
        Log.i(TAG, "onInterstitialShow");
        // 添加广告事件
        sendEvent(AdEventAction.onAdExposure);
    }

    @Override
    public void onInterstitialShowFail(@NonNull AdError adError) {
        Log.e(TAG, "onInterstitialLoadFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
    }

    @Override
    public void onInterstitialAdClick() {
        Log.i(TAG, "onInterstitialAdClick");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClicked);
    }

    @Override
    public void onInterstitialClosed() {
        Log.i(TAG, "onInterstitialClosed");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClosed);
        if (ad != null) {
            ad.destroy();
            ad = null;
        }
    }

    @Override
    public void onAdOpened() {
        Log.i(TAG, "onAdOpened");
    }

    @Override
    public void onAdLeftApplication() {
        Log.i(TAG, "onAdLeftApplication");
    }
}