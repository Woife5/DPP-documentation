<script setup lang="ts">
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { onMounted, ref, computed } from 'vue'
import {
  besAirService,
  type BesnLanguageOption,
  besnLanguageOptions,
} from '@/services/bes-air.service'
import { useI18n } from 'vue-i18n'
import { useMutation, useQuery, useQueryClient } from 'vue-query'

const queryClient = useQueryClient()
const {
  data: queryData,
  error: queryError,
  isLoading: isLoadingQuery,
} = useLangQuery()
const {
  mutate,
  error: mutateError,
  isLoading: isLoadingMutation,
} = useLangMutation()

const isLoading = computed(
  () => isLoadingQuery.value || isLoadingMutation.value
)
const isError = computed(
  () => queryError.value != null || mutateError.value != null
)

function useLangQuery() {
  return useQuery('q-audio-language', () => besAirService.getLanguage())
}

function useLangMutation() {
  return useMutation(
    'm-audio-language',
    (language: BesnLanguageOption) => besAirService.setLanguage(language),
    {
      onSuccess: () => {
        queryClient.invalidateQueries(['q-audio-language'])
      },
    }
  )
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
          @click="mutate(languageOption)"
          :checked="languageOption === selectedBesnLanguage"
          :title="languageOption"
        />
      </div>
      <div
        v-if="isError"
        class="mt-2 text-red-700 dark:text-red-500 flex items-center gap-2"
      >
        <i class="material-icons">error</i>
        <span>{{ $t('bes-air-service.error.no-response') }}</span>
      </div>
    </fieldset>
  </article>
</template>
