TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core widgets

SOURCES += \
        main.cpp \
    main.cpp

HEADERS += \    
    baseinclude.h \    
    ../10_简化函数调用/10_0_overview.h \
    ../10_简化函数调用/10_10_remove_setting_method.h \
    ../10_简化函数调用/10_11_hide_method.h \
    ../10_简化函数调用/10_12_replace_constructor_with_factory_method.h \
    ../10_简化函数调用/10_13_encapsulate_downcast.h \
    ../10_简化函数调用/10_14_replace_error_code_with_exception.h \
    ../10_简化函数调用/10_15_replace_exception_with_test.h \
    ../10_简化函数调用/10_1_rename_method.h \
    ../10_简化函数调用/10_2_add_parameter.h \
    ../10_简化函数调用/10_3_remove_parameter.h \
    ../10_简化函数调用/10_4_separate_query_from_modifier.h \
    ../10_简化函数调用/10_5_parameterize_method.h \
    ../10_简化函数调用/10_6_replace_parameter_with_explicit_methods.h \
    ../10_简化函数调用/10_7_preserve_whole_object.h \
    ../10_简化函数调用/10_8_replace_parameter_with_methods.h \
    ../10_简化函数调用/10_9_introduce_parameter_object.h \
    ../11_处理概括关系/11_0_overview.h \
    ../11_处理概括关系/11_10_from_template_method.h \
    ../11_处理概括关系/11_11_replace_inheritance_with_delegation.h \
    ../11_处理概括关系/11_12_replace_delegation_with_inheritance.h \
    ../11_处理概括关系/11_1_pull_up_field.h \
    ../11_处理概括关系/11_2_pull_up_method.h \
    ../11_处理概括关系/11_3_pull_up_constructor_body.h \
    ../11_处理概括关系/11_4_push_down_method.h \
    ../11_处理概括关系/11_5_push_down_field.h \
    ../11_处理概括关系/11_6_extract_subclass.h \
    ../11_处理概括关系/11_7_extract_superclass.h \
    ../11_处理概括关系/11_8_extract_interface.h \
    ../11_处理概括关系/11_9_collapse_hierachy.h \
    ../6_重新组织函数/6_0_overview.h \
    ../6_重新组织函数/6_1_extractmethod.h \
    ../6_重新组织函数/6_2_inlinemethod.h \
    ../6_重新组织函数/6_3_inlinetemp.h \
    ../6_重新组织函数/6_4_replacetempwithquery.h \
    ../6_重新组织函数/6_5_introduce_explaining_variable.h \
    ../6_重新组织函数/6_6_split_temp_variable.h \
    ../6_重新组织函数/6_7_remove_asignment_to_parameters.h \
    ../6_重新组织函数/6_8_replace_method_with_method_object.h \
    ../6_重新组织函数/6_9_substitute_algorithm.h \
    ../7_在对象之间搬移特性/7_0_overview.h \
    ../7_在对象之间搬移特性/7_1_movemethod.h \
    ../7_在对象之间搬移特性/7_2_movefield.h \
    ../7_在对象之间搬移特性/7_3_extractclass.h \
    ../7_在对象之间搬移特性/7_4_inineclass.h \
    ../7_在对象之间搬移特性/7_5_hidedelegate.h \
    ../7_在对象之间搬移特性/7_6_removemiddleman.h \
    ../7_在对象之间搬移特性/7_7_introduceforeignmethod.h \
    ../7_在对象之间搬移特性/7_8_introducelocalextension.h \
    ../8_重新组织数据/8_0_overview.h \
    ../8_重新组织数据/8_10_encapsulatefield.h \
    ../8_重新组织数据/8_11_encapsulatecollection.h \
    ../8_重新组织数据/8_12_replace_record_with_dataclass.h \
    ../8_重新组织数据/8_13_replacetypecodewithclass.h \
    ../8_重新组织数据/8_14_replace_typecode_with_subclasses.h \
    ../8_重新组织数据/8_15_replace_typecode_with_state_or_strategy.h \
    ../8_重新组织数据/8_16_replace_subclass_with_field.h \
    ../8_重新组织数据/8_1_selfencapsulate_field.h \
    ../8_重新组织数据/8_2_replacedatavaluewithobject.h \
    ../8_重新组织数据/8_3_change_value_to_reference.h \
    ../8_重新组织数据/8_4_change_reference_to_value.h \
    ../8_重新组织数据/8_5_replace_array_with_object.h \
    ../8_重新组织数据/8_6_duplicate_observed_data.h \
    ../8_重新组织数据/8_7_changeone2two.h \
    ../8_重新组织数据/8_8_changetwo2one.h \
    ../8_重新组织数据/8_9_magicnumber.h \
    ../9_简化条件表达式/9_0_overview.h \
    ../9_简化条件表达式/9_1_decompose_conditional.h \
    ../9_简化条件表达式/9_2_consolidate_conditional_expression.h \
    ../9_简化条件表达式/9_3_consolidate_duplicate_conditional_fragments.h \
    ../9_简化条件表达式/9_4_remove_control_flag.h \
    ../9_简化条件表达式/9_5_replace_nested_conditional_with_guard_clauses.h \
    ../9_简化条件表达式/9_6_replace_conditional_with_polymorphism.h \
    ../9_简化条件表达式/9_7_introduce_null_object.h \
    ../9_简化条件表达式/9_8_introduce_assertion.h \
    baseinclude.h
