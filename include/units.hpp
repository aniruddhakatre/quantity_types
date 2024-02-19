/**
 * @file units.hpp
 * @brief named units used by the quantity types for type-safety
 *
 */

#pragma once

#include "NamedType/named_type.hpp"

using Meter = fluent::NamedType<double, struct MeterTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Feet = fluent::NamedType<double, struct FeetTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Kilometer = fluent::NamedType<double, struct KilometerTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using NauticalMile = fluent::NamedType<double, struct NauticalMileTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;

using Second = fluent::NamedType<double, struct SecondTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Millisecond = fluent::NamedType<double, struct MillisecondTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Microsecond = fluent::NamedType<double, struct MicrosecondTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Minute = fluent::NamedType<double, struct MinuteTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Hour = fluent::NamedType<double, struct HourTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;

using Radian = fluent::NamedType<double, struct RadianTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Degree = fluent::NamedType<double, struct DegreeTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;

using MeterPerSec = fluent::NamedType<double, struct MeterPerSecTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using FeetPerMin = fluent::NamedType<double, struct FeetPerMinTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using Knots = fluent::NamedType<double, struct KnotsTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using KilometerPerHour = fluent::NamedType<double, struct KilometerPerHourTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;

using MeterPerSecSq = fluent::NamedType<double, struct MeterPerSecSqTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using FeetPerSecSq = fluent::NamedType<double, struct FeetPerSecSqTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
using AccelG = fluent::NamedType<double, struct AccelGTag, fluent::Addable, fluent::Subtractable, fluent::Comparable, fluent::Hashable>;
