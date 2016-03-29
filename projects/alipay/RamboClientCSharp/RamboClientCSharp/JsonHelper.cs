using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json.Serialization;
using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace System.Runtime.CompilerServices
{
    public class ExtensionAttribute : Attribute { }
}

namespace RamboClientCSharp
{
    public class JsonLowerCaseUnderscoreContractResolver : DefaultContractResolver
    {
        private Regex regex = new Regex("(?!(^[A-Z]))([A-Z])");

        protected override string ResolvePropertyName(string propertyName)
        {
            return regex.Replace(propertyName, "_$2").ToLower();
        }
    }

    public static class JsonHelper
    {
        static JsonLowerCaseUnderscoreContractResolver jsonContractResolver 
            = new JsonLowerCaseUnderscoreContractResolver();
        static JsonSerializer jsonSerializer = new JsonSerializer()
        {
            NullValueHandling = NullValueHandling.Ignore,
            ContractResolver = jsonContractResolver
        };
        static JsonSerializerSettings jsonSerializerSettings = new JsonSerializerSettings()
        {
            NullValueHandling = NullValueHandling.Ignore,
            ContractResolver = jsonContractResolver
        };

        public static T ToRamboObject<T>(JObject jObject)
        {
            return jObject.ToObject<T>(jsonSerializer);
        }

        public static JObject FromRamboObject(Object o)
        {
            return JObject.FromObject(o, jsonSerializer);
        }

        public static JObject FromRamboString(String str)
        {
            return new JObject(str);
        }

        public static T DeserializeRamboObject<T>(String value)
        {
            return JsonConvert.DeserializeObject<T>(value, jsonSerializerSettings);
        }

        public static String SerializeRamboObject(Object o)
        {
            return JsonConvert.SerializeObject(o, jsonSerializerSettings);
        }
    }
}
