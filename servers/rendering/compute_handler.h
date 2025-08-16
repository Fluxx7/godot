#pragma once

#include "core/object/worker_thread_pool.h"
#include "core/os/condition_variable.h"
#include "core/os/thread_safe.h"
#include "core/templates/local_vector.h"
#include "core/templates/rid_owner.h"
#include "core/variant/typed_array.h"
#include "servers/display_server.h"
#include "servers/rendering/rendering_device.h"

class ComputeHandler : Object {
    GDCLASS(ComputeHandler, Object)

private:
    RenderingDevice *rd_device;

protected:
    void _init();

public:
    ComputeHandler() {
        rd_device = nullptr;
    }
    ComputeHandler(RenderingDevice &rd) {
        rd_device = &rd;
    }

    RID get_kernel(int index);

    void add_shader(String filepath);

    void dispatch_shader();

};