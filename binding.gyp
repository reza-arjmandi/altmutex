{
  'targets': [
    {
      'target_name': 'addon',
      'include_dirs': [
        "<!@(node -p \"require('node-addon-api').include\")",
      ],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'conditions': [
        [
          'OS==\'win\'',
          {
            'win_delay_load_hook': 'true',
            'sources': [
              'addon.cpp'
            ],
            'configurations' : {
              'Release': {
                'msvs_settings': {
                  'VCCLCompilerTool': {
                    'AdditionalOptions': [ '/clr' ],
                    'RuntimeLibrary': 2,
                    'RuntimeTypeInfo': 'true'
                  },
                  'VCLinkerTool': {
                    'ExceptionHandling': 1,
                    'DelayLoadDLLs': [ 'node.exe' ],
                    'AdditionalOptions': [ '/ignore:4248' ],
                    'LinkTimeCodeGeneration': 0
                  }
                }
              }
            }
          }
        ]
      ]
    }
  ]
}
