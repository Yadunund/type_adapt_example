// Copyright 2022 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "type_adapt_example/image_sub_no_type_adapt_node.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "sensor_msgs/msg/image.hpp"

namespace type_adapt_example
{

ImageSubNoTypeAdaptNode::ImageSubNoTypeAdaptNode(const rclcpp::NodeOptions & options)
: rclcpp::Node("image_sub_no_type_adapt", options)
{
  auto callback =
    [this](sensor_msgs::msg::Image::UniquePtr msg) -> void
    {
      (void)msg;
      RCLCPP_INFO(this->get_logger(), "Image received");
    };

  sub_ = create_subscription<sensor_msgs::msg::Image>("image", 10, callback);
}

ImageSubNoTypeAdaptNode::~ImageSubNoTypeAdaptNode()
{
}

}  // namespace type_adapt_example

RCLCPP_COMPONENTS_REGISTER_NODE(type_adapt_example::ImageSubNoTypeAdaptNode)
