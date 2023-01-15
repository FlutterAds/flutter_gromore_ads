package com.zero.flutter_gromore_ads.page;

import android.content.Context;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.bytedance.msdk.api.v2.GMDislikeCallback;
import com.bytedance.msdk.api.v2.ad.nativeAd.GMNativeAd;
import com.bytedance.msdk.api.v2.ad.nativeAd.GMNativeExpressAdListener;
import com.zero.flutter_gromore_ads.PluginDelegate;
import com.zero.flutter_gromore_ads.event.AdEventAction;
import com.zero.flutter_gromore_ads.load.FeedAdManager;
import com.zero.flutter_gromore_ads.utils.UIUtils;

import java.util.HashMap;
import java.util.Map;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.platform.PlatformView;

/**
 * Feed 信息流广告 View
 */
class AdFeedView extends BaseAdPage implements PlatformView, GMNativeExpressAdListener, View.OnLayoutChangeListener {
    private final String TAG = AdFeedView.class.getSimpleName();
    @NonNull
    private final FrameLayout frameLayout;
    private final PluginDelegate pluginDelegate;
    private int id;
    private GMNativeAd fad;
    private View adView;
    private MethodChannel methodChannel;


    AdFeedView(@NonNull Context context, int id, @Nullable Map<String, Object> creationParams, PluginDelegate pluginDelegate) {
        this.id = id;
        this.pluginDelegate = pluginDelegate;
        methodChannel = new MethodChannel(this.pluginDelegate.bind.getBinaryMessenger(), PluginDelegate.KEY_FEED_VIEW + "/" + id);
        frameLayout = new FrameLayout(context);
        frameLayout.addOnLayoutChangeListener(this);
        MethodCall call = new MethodCall("AdFeedView", creationParams);
        showAd(this.pluginDelegate.activity, call);
    }

    @NonNull
    @Override
    public View getView() {
        return frameLayout;
    }

    @Override
    public void dispose() {
        removeAd();
    }

    @Override
    public void loadAd(@NonNull MethodCall call) {
        fad = FeedAdManager.getInstance().getAd(Integer.parseInt(this.posId));
        if (fad != null) {
            fad.setNativeAdListener(this);
            bindDislikeAction(fad);
            View expressView = fad.getExpressView();
            adView = expressView;
            if (expressView != null && expressView.getParent() != null) {
                ((ViewGroup) expressView.getParent()).removeAllViews();
            }
            FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, UIUtils.getScreenHeightInPx(activity));
            frameLayout.setLayoutParams(params);
            frameLayout.addView(expressView);
            fad.render();
            frameLayout.requestLayout();
        }
    }

    /**
     * 移除广告
     */
    private void removeAd() {
        frameLayout.removeAllViews();
    }

    /**
     * 销毁广告
     */
    private void disposeAd() {
        removeAd();
        FeedAdManager.getInstance().removeAd(Integer.parseInt(this.posId));
        if (fad != null) {
            fad.destroy();
        }
        // 更新宽高
        setFlutterViewSize(0f, 0f);
    }

    public void onAdClosed() {
        Log.i(TAG, "onAdDismiss");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClosed);
        disposeAd();
    }

    @Override
    public void onAdClick() {
        Log.i(TAG, "onAdClicked");
        // 添加广告事件
        sendEvent(AdEventAction.onAdClicked);
    }

    @Override
    public void onAdShow() {
        Log.i(TAG, "onAdShow");
        // 添加广告事件
        sendEvent(AdEventAction.onAdExposure);
    }

    @Override
    public void onRenderFail(View view, String s, int i) {
        Log.e(TAG, "onRenderFail code:" + i + " msg:" + s);
        // 添加广告错误事件
        sendErrorEvent(i, s);
        // 更新宽高
        setFlutterViewSize(0f, 0f);
    }

    @Override
    public void onRenderSuccess(float width, float height) {
        Log.i(TAG, "onRenderSuccess v:" + width + " v1:" + height);
        // 添加广告事件
        sendEvent(AdEventAction.onAdPresent);
        if (width > 0 && height > 0) {
            setFlutterViewSize(width, height);
        } else {
            resizeAdView(adView);
        }


    }

    /**
     * 重新计算真实的广告 View 的宽高
     */
    private void resizeAdView(View view) {
        Log.d(TAG, "resizeAdView fad mw:" + fad.getImageWidth() + " mh:" + fad.getImageHeight());
        view.post(new Runnable() {
            @Override
            public void run() {
                int width = view.getWidth();
                int height = view.getHeight();

                Log.d(TAG, "resizeAdView post View width:" + width + " height:" + height);

            }
        });
        int mwidth = View.getDefaultSize(10, ViewGroup.LayoutParams.WRAP_CONTENT);
        int mheight = View.getDefaultSize(10,ViewGroup.LayoutParams.WRAP_CONTENT);
        Log.d(TAG, "resizeAdView measure  mw:" + mwidth + " mh:" + mheight);
        frameLayout.measure(mwidth, mheight);
        int width = frameLayout.getMeasuredWidth();
        int height = frameLayout.getMeasuredHeight();
        Log.d(TAG, "resizeAdView mw:" + width + " mh:" + height);
        // Do something with the width and height
        FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(width, height);
        frameLayout.setLayoutParams(params);
        frameLayout.requestLayout();
        int widthPd = UIUtils.px2dip(activity, width);
        int heightPd = UIUtils.px2dip(activity, height);
        Log.i(TAG, "resizeAdView widthPd:" + widthPd + " heightPd:" + heightPd);
        setFlutterViewSize(widthPd, heightPd);
    }

    /**
     * 设置 FlutterAds 视图宽高
     *
     * @param width  宽度
     * @param height 高度
     */
    private void setFlutterViewSize(float width, float height) {

        // 更新宽高
        Map<String, Double> sizeMap = new HashMap<>();
        sizeMap.put("width", (double) width);
        sizeMap.put("height", (double) height);
        if (methodChannel != null) {
            methodChannel.invokeMethod("setSize", sizeMap);
        }
    }

    /**
     * 接入dislike 逻辑，有助于提示广告精准投放度
     * 和后续广告关闭逻辑处理
     *
     * @param ad 广告 View
     */
    private void bindDislikeAction(GMNativeAd ad) {
        ad.setDislikeCallback(activity, new GMDislikeCallback() {
            @Override
            public void onSelected(int position, String value) {
                onAdClosed();
            }

            @Override
            public void onCancel() {

            }

            @Override
            public void onRefuse() {

            }

            @Override
            public void onShow() {

            }
        });
    }

    @Override
    public void onLayoutChange(View v, int left, int top, int right, int bottom, int oldLeft, int oldTop, int oldRight, int oldBottom) {
//        Log.i(TAG, "onLayoutChange left:" + left + " top:" + top + " right:" + right + " bottom:" + bottom);

        if (right > 0 && bottom > 0) {
            int width = right - left;
            int height = bottom - top;
//            Log.i(TAG, "onLayoutChange width:" + width + " height:" + height);
//            setFlutterViewSize(width, height);
        }
    }


}