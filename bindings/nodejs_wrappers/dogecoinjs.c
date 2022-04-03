#include <assert.h>
#include <dogecoin/crypto/ecc.h>
#include <node_api.h>

static napi_value DogecoinEccStart(napi_env env, napi_callback_info info)
{
    napi_status status;
    napi_value world;

    // SYMBOL NOT FOUND
    // dogecoin_ecc_start();

    status = napi_create_string_utf8(env, "world", 5, &world);
    assert(status == napi_ok);
    return world;
}

#define DECLARE_NAPI_METHOD(name, func)         \
    {                                           \
        name, 0, func, 0, 0, 0, napi_default, 0 \
    }

static napi_value Init(napi_env env, napi_value exports)
{
    napi_status status;
    napi_property_descriptor desc = DECLARE_NAPI_METHOD("dogecoinEccStart", DogecoinEccStart);
    status = napi_define_properties(env, exports, 1, &desc);
    assert(status == napi_ok);
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
