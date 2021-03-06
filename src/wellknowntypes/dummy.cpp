/*
 * MIT License
 *
 * Copyright (c) 2020 Alexey Edelev <semlanik@gmail.com>
 *
 * This file is part of qtprotobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Well known types library consists of scope of autogenerated static libraries. This file is
 * dummy placeholder to make add_library call possible.
 */

/*!
 * \defgroup QtProtobufWellKnownTypes
 * \brief Google Protobuf Well-Known types library for QtProtobuf
 *
 * \details QtProtobufWellKnownTypes contains follwing <a href="https://developers.google.com/protocol-buffers/docs/reference/google.protobuf">Protobuf Well-Known types</a>:
 *    - Any
 *    - Timestamp
 *    - Struct
 *    - Value
 *    - ListValue
 *    - SourceContext
 *    - DoubleValue
 *    - FloatValue
 *    - Int64Value
 *    - UInt64Value
 *    - Int32Value
 *    - UInt32Value
 *    - BoolValue
 *    - StringValue
 *    - BytesValue
 *    - Type
 *    - Field
 *    - Enum
 *    - EnumValue
 *    - Option
 *    - Empty
 *    - FieldMask
 *    - Api
 *    - Method
 *    - Mixin
 *    - Duration
 *
 *
 * To use well-known type in your project you may include corresponding google .proto file in your interface:
 *
 * \code
 * syntax = "proto3";
 * package somepackage;
 *
 * import "google/protobuf/empty.proto";
 * import "google/protobuf/timestamp.proto";
 *
 * message AnimationMessage {
 *     uint32 animationId = 1;
 *     google.protobuf.Timestamp startTime = 2;
 *     google.protobuf.Timestamp endTime = 3;
 * }
 *
 * service AnimationService {
 *     rpc startAnimation(AnimationMessage) returns (google.protobuf.Empty) {}
 * }
 * \endcode
 *
 * It's also possible to use some of generated well-known types directly, simply include corresponding header:
 *
 * \code
 * #include <google/protobuf/any.qpb.h>
 * ...
 *     google::protobuf::Any someAnyVariable;
 *     someAnyVariable.setType_url("http://somedomain.org/someTypeDescription");
 *     someAnyVariable.setValue(data);
 * ...
 * \endcode
 *
 * In both scenarious you also need to link QtProtobuf WellKnownTypes library by adding following lines to
 * **CMakeLists.txt** for your target.
 * \code
 *     target_link_libraries(YourTargetName PRIVATE QtProtobuf::ProtobufWellKnownTypes)
 * \endcode
 */
