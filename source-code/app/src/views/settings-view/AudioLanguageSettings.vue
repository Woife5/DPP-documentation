<script setup lang="ts">
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { computed, type Ref } from 'vue'
import {
  besAirService,
  type BesnLanguageOption,
  besnLanguageOptions,
  type ResponseWithData,
} from '@/services/bes-air-rest.service'
import { useMutation, useQuery, useQueryClient } from 'vue-query'
import ConnectionPending from '@/components/ui/connection/ConnectionPending.vue'
import ConnectionError from '@/components/ui/connection/ConnectionError.vue'
import type { QueryDataRef } from '@/utilities/tanstack-types'

const queryClient = useQueryClient()
const {
  data: queryData,
  isLoading: isLoadingQuery,
  isFetching: isFetchingQuery,
  isError: isErrorQuery,
} = useQuery('q-audio-language', () => besAirService.getLanguage())

const {
  mutate,
  isLoading: isLoadingMutate,
  isError: isErrorMutate,
} = useMutation(
  'm-audio-language',
  (language: BesnLanguageOption) => besAirService.setLanguage(language),
  {
    onSuccess: (res) => {
      queryClient.setQueryData<QueryDataRef<typeof queryData>>(
        ['q-audio-language'],
        {
          data: {
            lang: res.data.lang,
          },
          response: new Response(),
        }
      )
    },
  }
)

const isPending = computed(() => isFetchingQuery.value)
const isError = computed(() => isErrorQuery.value || isErrorMutate.value)

const radioButtonsDisabled = computed(
  () =>
    isLoadingQuery.value ||
    isFetchingQuery.value ||
    isErrorQuery.value ||
    isLoadingMutate.value ||
    isErrorMutate.value
)

function onRadioButtonClick(languageOption: BesnLanguageOption) {
  if (radioButtonsDisabled.value) return
  mutate(languageOption)
}
</script>

<template>
  <article>
    <fieldset>
      <legend class="mb-2">
        <h1 class="flex items-center gap-2 text-2xl">
          <span>{{ $t('view.settings.besn-language.heading.label') }}</span>
          <i class="material-icons">language</i>
        </h1>
      </legend>

      <div class="flex flex-col items-start gap-y-1">
        <RadioButton
          v-for="languageOption of besnLanguageOptions"
          :id="`besn-lang-${languageOption}`"
          :key="`besn-lang-${languageOption}`"
          :label="$t(`besn-lang.${languageOption}.label`)"
          name="besn-lang"
          :value="languageOption"
          :checked="languageOption === queryData?.data.lang"
          :disabled="radioButtonsDisabled"
          :title="languageOption"
          @change="() => onRadioButtonClick(languageOption)"
        />
      </div>

      <ConnectionPending v-if="isPending" />
      <ConnectionError v-if="!isPending && isError" />
    </fieldset>
  </article>
</template>
