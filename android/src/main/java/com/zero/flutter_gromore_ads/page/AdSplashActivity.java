package com.zero.flutter_gromore_ads.page;

import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.AppCompatImageView;
import com.bytedance.msdk.api.AdError;
import com.bytedance.msdk.api.v2.GMAdConstant;
import com.bytedance.msdk.api.v2.ad.splash.GMSplashAd;
import com.bytedance.msdk.api.v2.ad.splash.GMSplashAdListener;
import com.bytedance.msdk.api.v2.ad.splash.GMSplashAdLoadCallback;
import com.bytedance.msdk.api.v2.slot.GMAdSlotSplash;
import com.zero.flutter_gromore_ads.PluginDelegate;
import com.zero.flutter_gromore_ads.R;
import com.zero.flutter_gromore_ads.event.AdErrorEvent;
import com.zero.flutter_gromore_ads.event.AdEvent;
import com.zero.flutter_gromore_ads.event.AdEventAction;
import com.zero.flutter_gromore_ads.event.AdEventHandler;
import com.zero.flutter_gromore_ads.utils.StatusBarUtils;
import com.zero.flutter_gromore_ads.utils.UIUtils;

/**
 * 开屏广告
 */
public class AdSplashActivity extends AppCompatActivity implements GMSplashAdListener, GMSplashAdLoadCallback {
    private final String TAG = AdSplashActivity.class.getSimpleName();
    // 广告容器
    private FrameLayout ad_container;
    // 自定义品牌 logo
    private AppCompatImageView ad_logo;
    // 广告位 id
    private String posId;
    // 开屏广告
    private GMSplashAd gmSplashAd;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        UIUtils.hideBottomUIMenu(this);
        StatusBarUtils.setTranslucent(this);
        setContentView(R.layout.activity_ad_splash);
        initView();
        initData();
    }

    /**
     * 初始化View
     */
    private void initView() {
        ad_container = findViewById(R.id.splash_ad_container);
        ad_logo = findViewById(R.id.splash_ad_logo);
    }

    /**
     * 初始化数据
     */
    private void initData() {
        // 获取参数
        posId = getIntent().getStringExtra(PluginDelegate.KEY_POSID);
        String logo = getIntent().getStringExtra(PluginDelegate.KEY_LOGO);
        int buttonType = getIntent().getIntExtra(PluginDelegate.KEY_SPLASH_BUTTON_TYPE, GMAdConstant.SPLASH_BUTTON_TYPE_FULL_SCREEN);
        double timeout = getIntent().getDoubleExtra(PluginDelegate.KEY_TIMEOUT, 3.5);
        int absTimeout = (int) (timeout * 1000);
        // 判断是否有 Logo
        boolean hasLogo = !TextUtils.isEmpty(logo);
        if (hasLogo) {
            // 加载 logo
            int resId = getMipmapId(logo);
            hasLogo = resId > 0;
            if (hasLogo) {
                ad_logo.setVisibility(View.VISIBLE);
                ad_logo.setImageResource(resId);
            } else {
                Log.e(TAG, "Logo 名称不匹配或不在 mipmap 文件夹下，展示全屏");
            }
        }
        int width = (int) UIUtils.getScreenWidthInPx(this);
        int height = (int) UIUtils.getScreenHeightInPx(this);
        // 判断最终的 Logo 是否显示
        if (!hasLogo) {
            ad_logo.setVisibility(View.GONE);
        } else {
            // 显示 Logo 高度去掉 Logo 的高度
            height = height - ad_logo.getLayoutParams().height;
        }
        // 创建开屏广告
        gmSplashAd = new GMSplashAd(this, posId);
        gmSplashAd.setAdSplashListener(this);
        GMAdSlotSplash adSlot = new GMAdSlotSplash.Builder()
                .setImageAdSize(width, height) // 既适用于原生类型，也适用于模版类型。
                .setTimeOut(absTimeout)//设置超时
                .setSplashButtonType(buttonType)
                .setDownloadType(GMAdConstant.DOWNLOAD_TYPE_POPUP)
                .build();
        // 加载广告
        gmSplashAd.loadAd(adSlot,this);
    }

    /**
     * 完成广告，退出开屏页面
     */
    private void finishPage() {
        finish();
        // 设置退出动画
        overridePendingTransition(android.R.anim.fade_in, android.R.anim.fade_out);
    }

    /**
     * 开屏页一定要禁止用户对返回按钮的控制，否则将可能导致用户手动退出了App而广告无法正常曝光和计费
     */
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK || keyCode == KeyEvent.KEYCODE_HOME) {
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }

    /**
     * 获取图片资源的id
     *
     * @param resName 资源名称，不带后缀
     * @return 返回资源id
     */
    private int getMipmapId(String resName) {
        return getResources().getIdentifier(resName, "mipmap", getPackageName());
    }

    @Override
    public void onAdClicked() {
        Log.d(TAG, "onAdClicked");
        AdEventHandler.getInstance().sendEvent(new AdEvent(this.posId, AdEventAction.onAdClicked));
    }

    @Override
    public void onAdShow() {
        Log.d(TAG, "onAdShow");
        AdEventHandler.getInstance().sendEvent(new AdEvent(this.posId, AdEventAction.onAdExposure));
    }

    @Override
    public void onAdShowFail(@NonNull AdError adError) {
        Log.e(TAG, "onAdShowFail code:" + adError.code + " msg:" + adError.message);
        AdEventHandler.getInstance().sendEvent(new AdErrorEvent(this.posId, adError.code, adError.message));
    }

    @Override
    public void onAdSkip() {
        Log.d(TAG, "onAdSkip");
        AdEventHandler.getInstance().sendEvent(new AdEvent(this.posId, AdEventAction.onAdSkip));
        finishPage();
    }

    @Override
    public void onAdDismiss() {
        Log.d(TAG, "onAdDismiss");
        AdEventHandler.getInstance().sendEvent(new AdEvent(this.posId, AdEventAction.onAdClosed));
        finishPage();
    }

    @Override
    public void onSplashAdLoadFail(@NonNull AdError adError) {
        Log.e(TAG, "onSplashAdLoadFail code:" + adError.code + " msg:" + adError.message);
        AdEventHandler.getInstance().sendEvent(new AdErrorEvent(this.posId, adError.code, adError.message));
        finishPage();
    }

    @Override
    public void onSplashAdLoadSuccess() {
        Log.d(TAG, "onSplashAdLoad");
        //获取SplashView
        if (!this.isFinishing()) {
            ad_container.removeAllViews();
            gmSplashAd.showAd(ad_container);
        } else {
            finishPage();
        }
        // 加载事件
        AdEventHandler.getInstance().sendEvent(new AdEvent(this.posId, AdEventAction.onAdLoaded));
    }

    @Override
    public void onAdLoadTimeout() {
        Log.e(TAG, "onAdLoadTimeout");
        finishPage();
    }
}