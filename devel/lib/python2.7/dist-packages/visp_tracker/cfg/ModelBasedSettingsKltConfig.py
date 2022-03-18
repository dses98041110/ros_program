## *********************************************************
##
## File autogenerated for the visp_tracker package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 246, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 291, 'description': 'Maximal angle value to consider an appearing face', 'max': 90.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'angle_appear', 'edit_method': '', 'default': 65.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 291, 'description': 'Minimal angle value to consider that a face disappear', 'max': 90.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'angle_disappear', 'edit_method': '', 'default': 75.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 291, 'description': 'Face dead zone size', 'max': 50, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'mask_border', 'edit_method': '', 'default': 5, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 291, 'description': 'Maximum number of KLT features', 'max': 30000, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'max_features', 'edit_method': '', 'default': 10000, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 291, 'description': 'Window size arround a KLT point', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'window_size', 'edit_method': '', 'default': 5, 'level': 0, 'min': 3, 'type': 'int'}, {'srcline': 291, 'description': 'Quality threshold used to consider that a point is valid', 'max': 0.1, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'quality', 'edit_method': '', 'default': 0.05, 'level': 0, 'min': 0.0001, 'type': 'double'}, {'srcline': 291, 'description': 'Min distance between two points', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'min_distance', 'edit_method': '', 'default': 5.0, 'level': 0, 'min': 1.0, 'type': 'double'}, {'srcline': 291, 'description': 'Harris value', 'max': 0.1, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'harris', 'edit_method': '', 'default': 0.01, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 291, 'description': 'Block size', 'max': 10, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'size_block', 'edit_method': '', 'default': 3, 'level': 0, 'min': 2, 'type': 'int'}, {'srcline': 291, 'description': 'Number of levels in the pyramid', 'max': 5, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'pyramid_lvl', 'edit_method': '', 'default': 3, 'level': 0, 'min': 0, 'type': 'int'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

