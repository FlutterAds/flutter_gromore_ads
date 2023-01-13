package com.zero.flutter_gromore_ads.page;

import android.content.Context;
import android.text.TextUtils;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;


import com.bumptech.glide.Glide;
import com.bytedance.msdk.api.AdError;
import com.bytedance.msdk.api.TToast;
import com.bytedance.msdk.api.nativeAd.TTNativeAdAppInfo;
import com.bytedance.msdk.api.nativeAd.TTViewBinder;
import com.bytedance.msdk.api.v2.GMAdConstant;
import com.bytedance.msdk.api.v2.GMAdDislike;
import com.bytedance.msdk.api.v2.GMAdSize;
import com.bytedance.msdk.api.v2.GMDislikeCallback;
import com.bytedance.msdk.api.v2.ad.banner.GMBannerAd;
import com.bytedance.msdk.api.v2.ad.banner.GMBannerAdListener;
import com.bytedance.msdk.api.v2.ad.banner.GMBannerAdLoadCallback;
import com.bytedance.msdk.api.v2.ad.banner.GMNativeAdInfo;
import com.bytedance.msdk.api.v2.ad.banner.GMNativeToBannerListener;
import com.bytedance.msdk.api.v2.ad.nativeAd.GMViewBinder;
import com.bytedance.msdk.api.v2.slot.GMAdSlotBanner;
import com.zero.flutter_gromore_ads.PluginDelegate;
import com.zero.flutter_gromore_ads.R;
import com.zero.flutter_gromore_ads.event.AdEventAction;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.platform.PlatformView;

/**
 * Banner 广告 View
 */
class AdBannerView extends BaseAdPage implements PlatformView, GMBannerAdListener, GMBannerAdLoadCallback {
    private final String TAG = AdBannerView.class.getSimpleName();
    @NonNull
    private final FrameLayout frameLayout;
    private final PluginDelegate pluginDelegate;
    private final int id;
    private GMBannerAd bad;


    AdBannerView(@NonNull Context context, int id, @Nullable Map<String, Object> creationParams, PluginDelegate pluginDelegate) {
        this.id = id;
        this.pluginDelegate = pluginDelegate;
        frameLayout = new FrameLayout(context);
        MethodCall call = new MethodCall("AdBannerView", creationParams);
        showAd(this.pluginDelegate.activity, call);
    }

    @NonNull
    @Override
    public View getView() {
        return frameLayout;
    }

    @Override
    public void dispose() {
        disposeAd();
    }

    @Override
    public void loadAd(@NonNull MethodCall call) {
        // 获取请求模板广告素材的尺寸
        int expressViewWidth = call.argument("width");
        int expressViewHeight = call.argument("height");
        bad = new GMBannerAd(activity, posId);
        // 设置广告事件监听
        bad.setAdBannerListener(this);
        // 设置广告配置
        GMAdSlotBanner slotBanner = new GMAdSlotBanner.Builder()
                .setBannerSize(GMAdSize.BANNER_CUSTOME)
                .setImageAdSize(expressViewWidth, expressViewHeight)// GMAdSize.BANNER_CUSTOME可以调用setImageAdSize设置大小
                .setMuted(true) // 控制视频是否静音
                .build();
        // 加载广告
        bad.loadAd(slotBanner, this);
    }

    /**
     * 销毁广告
     */
    private void disposeAd() {
        frameLayout.removeAllViews();
        if (bad != null) {
            bad.destroy();
        }
    }

    @Override
    public void onAdClicked() {
        Log.i(TAG, "onAdClicked");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClicked);
    }

    @Override
    public void onAdClosed() {
        Log.i(TAG, "onAdClosed");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClosed);
        disposeAd();
    }

    @Override
    public void onAdLeftApplication() {

    }

    @Override
    public void onAdOpened() {

    }

    @Override
    public void onAdShow() {
        Log.i(TAG, "onAdShow");
        // 添加广告事件
        sendEvent(AdEventAction.onAdExposure);
    }

    @Override
    public void onAdShowFail(@NonNull AdError adError) {
        Log.e(TAG, "onAdShowFail code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
        disposeAd();
    }

    @Override
    public void onAdFailedToLoad(@NonNull AdError adError) {
        Log.e(TAG, "onAdFailedToLoad code:" + adError.code + " msg:" + adError.message);
        sendErrorEvent(adError.code, adError.message);
        disposeAd();
    }

    @Override
    public void onAdLoaded() {
        Log.i(TAG, "onAdLoaded");
        if (bad != null && bad.isReady()) {
            frameLayout.removeAllViews();
            frameLayout.addView(bad.getBannerView());
            // 添加广告事件
            sendEvent(AdEventAction.onAdPresent);
        }
        // 添加广告事件
        sendEvent(AdEventAction.onAdLoaded);
    }

}