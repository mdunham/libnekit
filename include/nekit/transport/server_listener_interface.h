// MIT License

// Copyright (c) 2017 Zhuhao Wang

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <functional>
#include <system_error>

#include "../stream_coder/server_stream_coder_interface.h"
#include "../utils/async_io_interface.h"
#include "listener_interface.h"

namespace nekit {
namespace transport {
class ServerListenerInterface : public utils::AsyncIoInterface {
 public:
  using EventHandler = std::function<void(
      std::unique_ptr<ConnectionInterface>,
      std::unique_ptr<stream_coder::ServerStreamCoderInterface>,
      std::error_code)>;

  ServerListenerInterface(boost::asio::io_service& io) : AsyncIoInterface{io} {}

  virtual ~ServerListenerInterface() = default;

  virtual void Accept(EventHandler handler) = 0;
};
}  // namespace transport
}  // namespace nekit
