#include <private/internal-components.h>
static const struct hwloc_component * hwloc_static_components[] = {
  &hwloc_noos_component,
  &hwloc_xml_component,
  &hwloc_synthetic_component,
  &hwloc_xml_nolibxml_component,
  &hwloc_linux_component,
  &hwloc_opencl_component,
  &hwloc_cuda_component,
  &hwloc_nvml_component,
  &hwloc_xml_libxml_component,
  &hwloc_x86_component,
  NULL
};
