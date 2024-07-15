#include <iostream>
#include <vector>

using namespace std;

class IDevice {
};

class ICameraDevice : public IDevice {
public:
    virtual string getVersion() const = 0;

    virtual bool start() = 0;

    virtual bool stop() = 0;

    virtual ~ICameraDevice() {};
};

class UbuntuDriverOpenSource : public ICameraDevice {
public:
    string getVersion() const override { return "Ubuntu Open Source"; }

    bool start() override { return true; }

    bool stop() override { return false; }

    ~UbuntuDriverOpenSource() {}
};

class UbuntuDriver3dParty : public ICameraDevice {
public:
    string getVersion() const override { return "Ubuntu 3d party"; }

    bool start() override { return true; }

    bool stop() override { return false; }

    ~UbuntuDriver3dParty() override {}
};

class UbuntuDriverWindows10 : public ICameraDevice {
public:
    string getVersion() const override { return "Windows 10"; }

    bool start() override { return true; }

    bool stop() override { return false; }

    ~UbuntuDriverWindows10() override {}
};

class App {
protected:
    string appInfo;

public:
    virtual void run() = 0;

    virtual void shutdown() = 0;

    virtual ~App() {}
};

class CameraAppCheese : public App {
private:
    ICameraDevice *camera;

public:
    CameraAppCheese(ICameraDevice *camera_) : camera(camera_) {}

    void run() override {
        // Record images/videos
        for (int i = 0; i < 5; ++i) {
            cout << "CameraAppCheese - I am fast\n";
        }
    }

    void shutdown() override {}

    ~CameraAppCheese() {}
};

class CameraAppKamoso : public App {
private:
    ICameraDevice *camera;

public:
    CameraAppKamoso(ICameraDevice *camera_) : camera(camera_) {}

    void run() override {
        // Record images/videos
        for (int i = 0; i < 5; ++i) {
            cout << "CameraAppKamoso - I am fast\n";
        }
    }

    void shutdown() override {}

    ~CameraAppKamoso() {}
};

class UbuntuOs {
private:
    vector<IDevice *> devices;
    vector<App *> apps;

public:
    App *getCameraApp(string appName) {
        ICameraDevice *driver = new UbuntuDriverOpenSource();
        App *app = nullptr;

        if (appName == "Cheese") app = new CameraAppCheese(driver);
        else if (appName == "kamaso")app = new CameraAppKamoso(driver);
        else return nullptr;

        devices.push_back(driver);
        apps.push_back(app);
        return app;
    }

    void shutdown() {
        for (auto app: apps) app->shutdown();
    }

    ~UbuntuOs() {
        cout << "OS Terminate\n";
        shutdown();
        for (auto app: apps) delete app;
        apps.clear();
        for (auto device: devices) delete device;
        devices.clear();
    }
};

int main() {
    UbuntuOs os;

    App *app = os.getCameraApp("Cheese");

    if (app != nullptr)
        app->run();

    return 0;
}