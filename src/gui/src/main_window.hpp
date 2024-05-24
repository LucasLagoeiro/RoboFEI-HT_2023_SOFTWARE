#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QVector>
#include <QLineEdit>

#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int8.hpp>

// #include "custom_interfaces/msg/set_position_original.hpp"
#include "custom_interfaces/msg/joint_state.hpp"

using std::placeholders::_1;

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public rclcpp::Node
{
  Q_OBJECT

public:
  using JointStateMsg = custom_interfaces::msg::JointState;
  
  void jointPositionCallback(const JointStateMsg::SharedPtr all_joints_position);

  explicit MainWindow(
    const rclcpp::NodeOptions & node_options,
    QWidget * parent = nullptr);
  ~MainWindow() override;

private:
  Ui::MainWindow * ui_;

  QVector<QLineEdit*> allPosLineEdit;

  rclcpp::Publisher<JointStateMsg>::SharedPtr torque_publisher_;
  rclcpp::Subscription<JointStateMsg>::SharedPtr position_subscriber_;

  rclcpp::TimerBase::SharedPtr timer_;

  const std::string prefix_;

  void torque_checkbox_changed();
  void send_torque_info(int id, int torque);
  void publishJointStates();
};