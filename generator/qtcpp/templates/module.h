{# Copyright (c) Pelagicore AB 2016 #}
{% from 'helper.tpl' import qualifiedModuleName %}
/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/
{% set moduleName = qualifiedModuleName(module) %}
{% set class = 'Qml{0}'.format(moduleName) %}

#pragma once

#include <QtCore>

{% for struct in module.structs %}
#include "{{struct|lower}}.h"
#include "{{struct|lower}}model.h"
{% endfor %}

class {{class}} : public QObject {
    Q_OBJECT
public:
    {{class}}(QObject *parent=0);

{% for enum in module.enums %}
    {% set comma = joiner(",") %}
    enum {{enum}} { 
        {%- for member in enum.members -%}
        {{ comma() }}
        {{member.name}} = {{member.value}}
        {%- endfor %}
    };
    Q_ENUM({{enum}})
{% endfor %}

{% for struct in module.structs %}
    Q_INVOKABLE {{struct}} create{{struct}}();
{% endfor %}

    static void registerTypes();
    static void registerQmlTypes(const QString& uri, int majorVersion = 1, int minorVersion = 0);
};
