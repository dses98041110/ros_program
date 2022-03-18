
"use strict";

let SetSmartServoLinSpeedLimits = require('./SetSmartServoLinSpeedLimits.js')
let SetWorkpiece = require('./SetWorkpiece.js')
let SetSpeedOverride = require('./SetSpeedOverride.js')
let SetPTPCartesianSpeedLimits = require('./SetPTPCartesianSpeedLimits.js')
let SetSmartServoJointSpeedLimits = require('./SetSmartServoJointSpeedLimits.js')
let SetEndpointFrame = require('./SetEndpointFrame.js')
let SetPTPJointSpeedLimits = require('./SetPTPJointSpeedLimits.js')
let TimeToDestination = require('./TimeToDestination.js')
let ConfigureControlMode = require('./ConfigureControlMode.js')

module.exports = {
  SetSmartServoLinSpeedLimits: SetSmartServoLinSpeedLimits,
  SetWorkpiece: SetWorkpiece,
  SetSpeedOverride: SetSpeedOverride,
  SetPTPCartesianSpeedLimits: SetPTPCartesianSpeedLimits,
  SetSmartServoJointSpeedLimits: SetSmartServoJointSpeedLimits,
  SetEndpointFrame: SetEndpointFrame,
  SetPTPJointSpeedLimits: SetPTPJointSpeedLimits,
  TimeToDestination: TimeToDestination,
  ConfigureControlMode: ConfigureControlMode,
};
