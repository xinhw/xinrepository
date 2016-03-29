#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include <QtCore>

#define JSON_PROPERTY(type,name,key) \
    type get##name()const{ return getValue<type>(#key);}\
    void set##name(type value){setValue<type>(#key, value);}

#define JSON_PROPERTY2(type,name) \
    type get##name()const{ return getValue<type>(#name);}\
    void set##name(type value){setValue<type>(#name, value);}

#define JSON_LIST_PROPERTY(type,name,key) \
    QList<type> get##nameList()const{ return getValueList<type>(#key);}\
    void set##nameList(QList<type> value){setValueList(#key, value);}

class JsonObject
{
public:
    JsonObject();
    JsonObject(const QString &data);
    JsonObject(const QVariantMap& variantMap);

    virtual QString toString(bool indent = false) const;
    virtual QVariantMap toVariantMap() const;
    virtual void fromString(const QString &data);
    virtual void fromVariantMap(const QVariantMap& variantMap);

    template <typename T>
    T getValue(const QString &name) const
    {
        return originalObject.value(name).value<T>();
    }

    template <typename T>
    void setValue(const QString &name, const T &t)
    {
        originalObject[name] = t;
    }

    template <typename T>
    QList<T> getValueList(const QString& name) const
    {
        QList<T> result;
        QVariantList variantList = getValue<QVariantList>(name);

        QVariantList::iterator iter = variantList.begin();
        while(iter != variantList.end())
        {
            T t;
            t.originalObject = iter->toMap();
            result.append(t);
            ++iter;
        }

        return result;
    }

    template <typename T>
    void setValueList(const QString &name, const QList<T> &valueList)
    {
        QVariantList variantList;

        typename QList<T>::const_iterator iter = valueList.constBegin();
        while(iter != valueList.end())
        {
            variantList.append(iter->originalObject);
            ++iter;
        }

        originalObject[name] = variantList;
    }

    template <typename T>
    static T fromJsonString(const QString& jsonString)
    {
        T t;
        t.fromString(jsonString);
        return t;
    }

    template <typename T>
    static T fromVariantMap(const QVariantMap& variantMap)
    {
        T t;
        t.originalObject = variantMap;
        return t;
    }

    static QString toJsonString(const QVariantMap& jsonObject, bool indent = false);
    static QVariantMap fromJsonString(const QString& jsonString);

protected:

    QVariantMap originalObject;
};

#endif // JSONOBJECT_H
