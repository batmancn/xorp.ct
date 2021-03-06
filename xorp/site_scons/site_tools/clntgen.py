import SCons.Action
import SCons.Builder

clntgen_action = SCons.Action.Action("$CLNTGEN -I${TARGET.dir}/../.. --output-dir ${TARGET.dir} ${SOURCE}")

def clntgen_emitter(target, source, env):
    base,ext = SCons.Util.splitext(str(source[0]))
    base = base[base.rfind("/") + 1:]
    cc = base + "_xif.cc"
    hh = base + "_xif.hh"
    t = [cc, hh]
    return (t, source)

clntgen_builder = SCons.Builder.Builder(
    action = clntgen_action,
    src_suffix = ".xif",
    emitter = clntgen_emitter)

def generate(env):
    """Add Builder for XRL interfaces to the Environment ..."""

    env['BUILDERS']['CLNTGEN'] = clntgen_builder
    env['CLNTGEN'] = "$xorp_sourcedir/xrl/scripts/clnt-gen"

def exists(env):
    return True
